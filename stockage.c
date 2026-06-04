// CODE SUR LA CARTE 1 : GESTION DU STOCKAGE
const int capteurBatterie = A0; 
const int brocheSignalEnvoi = 3; // Fil relié à la broche D2 de la Carte 2

const float SEUIL_CRITIQUE = 4.8; 
const float SEUIL_OK = 5.2;       
bool autorisationDistribution = false;

void setup() {
  pinMode(brocheSignalEnvoi, OUTPUT);
  digitalWrite(brocheSignalEnvoi, LOW);
  Serial.begin(9600);
}

void loop() {
  int valeurBrute = analogRead(capteurBatterie);
  // Conversion en tension réelle (avec pont diviseur 10k / 4.7k)
  float tensionBatterie = (valeurBrute * 5.0 / 1023.0) * ((10.0 + 4.7) / 4.7);

  // Logique de décision de stockage
  if (tensionBatterie > SEUIL_OK) {
    autorisationDistribution = true;
  } else if (tensionBatterie < SEUIL_CRITIQUE) {
    autorisationDistribution = false;
  }

  // Envoi de l'ordre à la Carte 2
  if (autorisationDistribution) {
    digitalWrite(brocheSignalEnvoi, HIGH); // Signal "OUI, tu peux distribuer"
  } else {
    digitalWrite(brocheSignalEnvoi, LOW);  // Signal "NON, stockage trop bas"
  }

  Serial.print("Stockage - Tension: ");
  Serial.print(tensionBatterie);
  Serial.println(autorisationDistribution ? " V -> Autorisation: OK" : " V -> Autorisation: NON");

  delay(1000); 
}
