// Définition des broches (Pins)
const int BROCHE_LDR = A0;  // Le capteur de lumière (LDR) est branché sur la broche analogique A0
const int BROCHE_LED = 3;   // La LED est branchée sur la broche numérique 3 (compatible PWM si besoin)

// Seuil de luminosité (À ajuster selon votre pièce)
// La valeur lue varie entre 0 (noir total) et 1023 (pleine lumière)
const int SEUIL_NUIT = 300; 

void setup() {
  // Configuration des broches
  pinMode(BROCHE_LED, OUTPUT); // La broche de la LED est configurée en sortie
  
  // Initialisation du moniteur série pour afficher les valeurs à l'écran du PC
  Serial.begin(9600);
}

void loop() {
  // 1. Lire la valeur de la luminosité (photorésistance)
  int luminosite = analogRead(BROCHE_LDR);
  
  // 2. Afficher la valeur sur le moniteur série (pratique pour le réglage)
  Serial.print("Luminosite ambiante : ");
  Serial.println(luminosite);
  
  // 3. Condition : Si la luminosité descend en dessous du seuil, il fait nuit
  if (luminosite < SEUIL_NUIT) {
    digitalWrite(BROCHE_LED, HIGH); // Allumer la LED
  } 
  else {
    digitalWrite(BROCHE_LED, LOW);  // Éteindre la LED
  }
  
  // Petite pause de 200 millisecondes avant la prochaine lecture
  delay(200);
}
