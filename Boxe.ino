#include <TM1637Display.h>

// Définitions des broches
#define CLK 1
#define DIO 2
#define BUTTON_1 3
#define BUTTON_2 4
#define BUTTON_3 5
#define RESET_BUTTON 6

// Initialisation de l'afficheur TM1637
TM1637Display display(CLK, DIO);

// Variables globales
int score = 0;

// Configuration initiale
void setup() {
  // Configuration des broches boutons avec résistances pull-up internes
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(RESET_BUTTON, INPUT_PULLUP);

  // Initialisation de l'afficheur
  display.setBrightness(0x0F); // Luminosité maximale
  display.showNumberDec(0);    // Affiche 0 au démarrage
}

// Boucle principale
void loop() {
  // Vérifier les boutons (inverser la logique car pull-up est utilisé)
  if (digitalRead(BUTTON_1) == LOW) { // Bouton appuyé = LOW
    score += 1;
    delay(200); // Anti-rebond
  }
  if (digitalRead(BUTTON_2) == LOW) { // Bouton appuyé = LOW
    score += 2;
    delay(200); // Anti-rebond
  }
  if (digitalRead(BUTTON_3) == LOW) { // Bouton appuyé = LOW
    score += 4;
    delay(200); // Anti-rebond
  }
  if (digitalRead(RESET_BUTTON) == LOW) { // Bouton appuyé = LOW
    score = 0;
    delay(200); // Anti-rebond
  }

  // Mettre à jour l'affichage
  display.showNumberDec(score);
}
