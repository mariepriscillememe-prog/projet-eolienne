// Définition des broches (Pins)
const int BROCHE_LDR    = A0; // Capteur de lumière sur A0
const int BROCHE_BOUTON = 2;  // Bouton-poussoir sur la broche numérique 2
const int BROCHE_LED    = 3;  // LED sur la broche numérique 3

// Seuil de luminosité pour la nuit (0 = noir total, 1023 = pleine lumière)
const int SEUIL_NUIT = 300; 

void setup() {
  // Configuration des broches
  pinMode(BROCHE_LED, OUTPUT);
  
  // Utilisation de INPUT_PULLUP : active la résistance interne de l'Arduino.
  // Cela simplifie le câblage du bouton (pas besoin de résistance externe).
  // Attention : l'état du bouton sera LOW quand on appuie dessus, et HIGH relâché.
  pinMode(BROCHE_BOUTON, INPUT_PULLUP); 
  
  // Initialisation du moniteur série
  Serial.begin(9600);
}

void loop() {
  // 1. Lecture des capteurs
  int luminosite = analogRead(BROCHE_LDR);
  int etatBouton = digitalRead(BROCHE_BOUTON); // LOW = appuyé, HIGH = relâché
  
  // Affichage pour le débogage sur PC
  Serial.print("Luminosite : ");
  Serial.print(luminosite);
  Serial.print(" | Bouton presse : ");
  Serial.println(etatBouton == LOW ? "OUI" : "NON");
  
  // 2. Logique de contrôle
  // La LED s'allume si : il fait nuit (luminosite < SEUIL_NUIT) OU si le bouton est pressé (etatBouton == LOW)
  if ((luminosite < SEUIL_NUIT) || (etatBouton == LOW)) {
    digitalWrite(BROCHE_LED, HIGH); // Allumer la LED
  } 
  else {
    digitalWrite(BROCHE_LED, LOW);  // Éteindre la LED
  }
  
  delay(100); // Petite pause de stabilité
}
