/*
Code pour tester le fonctionnement des moteurs avec un ESC (speed controller).

ATTENTION : ESC fonctionnel seulement apres procedure de mise en route (voir consigne constructeur [cf fiche amazon]).

consignes : 
- Brancher les 3 cables de l'ESC avec le moteur
- Brancher le + et - de l'ESC avec une batterie (avec power distributor de preference (ou pas))

- Brancher connecteur orange de l'ESC avec un pin PWM (~)
- Brancher la masse (GND)

[- Brancher le VCC pour alimenter l'Arduino (si on veut, si il n'a pas deja une source d'energie)]


en gros : les ESC se commande comme des servomoteurs

pour changer le sens de rotation du moteur, il faut juste intervertir 2 des 3 fils connectés au moteur.

*/

#include <Servo.h>

Servo esc;   // Création de l'objet permettant le contrôle de l'ESC

//int val = 0;

void setup() {

   esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
   //delay(15);
   Serial.begin(9600);
   // Initialisation de l'ESC
   //  (certains ESC ont besoin d'une "procédure d'initialisation"
   //   pour devenir opérationnels - voir notice)
   esc.write(0);
   delay(1000);

   esc.write(180);
   delay(1000);
   
   esc.write(0);
   // Quelques informations pour l'utilisateur
   /*Serial.println("Saisir un nombre entre 0 et 179");
   Serial.println("(0 = arret - 179 = vitesse maxi");
   Serial.println(" demarrage a partir de 20)");*/

}
void loop() {

   /*if (Serial.available() > 0) {
      val = Serial.parseInt();   // lecture de la valeur passée par le port série
      Serial.println(val);
      esc.write(val);
      delay(15);
      }
    */

    esc.write(100);

}