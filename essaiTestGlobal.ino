
/* 

essai du programme global pour le drone  : 2 programmes (1 pour l'esp32-CAM [juste un stream video webServer]
1 pour l'esp32 [afficher le site avec la video sur un ip local / api avec GET request pour envoyer les commande au drone])

commande drone :
- avancer
- reculer
- droite
- gauche
- rotation droite
- rotation gauche
- haut
- bas

démarrer une connexion wifi

caméra bouge pas

(CW)    (CCW)
  -|  |-
   |  |             (ou inverse t'as captés)
  -|  |-
(CCW)   (CW)


MOUVEMENTS BASIQUES :

avancer : 

reculer :

(meme principe pour ces 4 mouvements)
principe : on diminue la vitesse des moteurs avants et augmente celle des moteurs arrière.

droite :

gauche : 

haut : on augmente la vitesse des 4 moteurs 

bas : on diminue la vitesse des 4 moteurs

rotation gauche : - vitesse moteur qui tourne vers la gauche, + V moteur qui tourne vers la droite

rotation droite : - vitesse moteur qui tourne vers la droite, + V moteur qui tourne vers la gauche


AJUSTEMENT DE POSITION / ORIENTATION :

capteurs de distance : 
----------------------

si on est avec la commande bas (descente)

si on est avec la commande avance && distance < x : Alors on diminue la vitesse. 
                                    si distance < x2 : on arrête d'avancer et on fait du sur-place.


gyroscope : 
-----------

4 variations :
vers la droite, la gauche, devant, derrière.

faire une fonction qui retourne le mouvement qui pose problème (gauche, droite, devant, derrière)

droite : on accélére les moteurs droit OU on décéllére les moteurs gauche
gauche : on accélére les moteurs gauche OU on décéllére les moteurs droite
devant : on accélére les moteurs avant OU on décéllére les moteurs arrière
arrière : on accélére les moteurs arrière OU on décéllére les moteurs avant


____________________

Améliorations si tout marche déjà et que c'est fini :

- attacher la caméra à un servo pour la faire bouger (en vertical)
- au lieu de bouton qui font bouger le drone tt le tps à la même vitesse, mettre un "joystick"

*/





void setup(){
    

}

void loop(){


}