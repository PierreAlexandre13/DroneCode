# DroneCode

Code embarqué d'un drone quadricoptère « fait maison » basé sur **ESP32**, piloté à distance depuis une page web via le Wi-Fi, avec retour vidéo en direct grâce à une **ESP32-CAM**.

> Projet en cours de développement : les briques matérielles sont testées séparément, le programme global (`essaiTestGlobal.ino`) n'est pas encore implémenté.

## Principe général

Le projet repose sur **deux microcontrôleurs** :

| Carte | Rôle |
|---|---|
| **ESP32-CAM** | Diffuse un flux vidéo via un serveur web |
| **ESP32** | Héberge la page de contrôle (IP locale) avec la vidéo, reçoit les commandes (requêtes HTTP `GET`) et pilote les 4 moteurs |

### Commandes prévues

Avancer, reculer, gauche, droite, rotation gauche, rotation droite, monter, descendre.

### Logique de mouvement

- **Avancer / reculer** : diminuer la vitesse des moteurs avant et augmenter celle des moteurs arrière (et inversement). Même principe pour **gauche / droite**.
- **Monter / descendre** : augmenter / diminuer la vitesse des 4 moteurs.
- **Rotation** : modifier la vitesse relative des moteurs tournant dans le sens horaire (CW) et antihoraire (CCW).

### Stabilisation et sécurité (prévu)

- **Gyroscope (MPU-6050)** : détecter la dérive (droite, gauche, avant, arrière) et compenser en accélérant/décélérant les moteurs concernés.
- **Capteur à ultrasons** : ralentir à l'approche d'un obstacle, puis faire du sur-place sous un seuil de distance.

### Améliorations envisagées

- Caméra montée sur un servomoteur (mouvement vertical).
- Remplacer les boutons (vitesse constante) par un joystick pour un contrôle proportionnel.

## Contenu du dépôt

| Fichier | Description |
|---|---|
| `essaiTestGlobal.ino` | Cahier des charges et squelette du programme global (commentaires de conception, `setup()`/`loop()` vides) |
| `esp32camStreamWebServer.ino` | Flux vidéo de l'ESP32-CAM via serveur web |
| `blinkWebServerEsp32.ino` | Test de l'ESP32 avec serveur web (contrôle d'une LED) |
| `mpuToEsp.ino` | Lecture du MPU-6050 (accéléromètre, gyroscope, température) sur l'ESP32 via I2C |
| `testMotor.ino` | Test d'un moteur brushless via un ESC |
| `UltrasonicSimple.ino` | Mesure de distance avec un capteur à ultrasons (HC-SR04 ou 3 broches) |
| `dossier/` | Ressources complémentaires |

## Matériel

- 1× ESP32 (contrôleur de vol + serveur web)
- 1× ESP32-CAM (streaming vidéo)
- 4× moteurs brushless + 4× ESC
- 1× module MPU-6050 (gyroscope / accéléromètre)
- 1× capteur à ultrasons (HC-SR04 ou équivalent)
- Batterie + répartiteur d'alimentation (power distributor)

## Câblage

### MPU-6050 → ESP32

| MPU-6050 | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SCL | GPIO 22 |
| SDA | GPIO 21 |
| INT | (optionnel) |

### ESC → carte

- Les 3 fils de l'ESC vers le moteur (intervertir 2 fils inverse le sens de rotation).
- `+` / `-` de l'ESC vers la batterie.
- Fil de signal (orange) vers une broche **PWM** (broche 9 dans `testMotor.ino`).
- Masse (GND) commune.

> Un ESC n'est opérationnel qu'après sa procédure d'initialisation (voir la notice du fabricant). `testMotor.ino` en effectue une basique (0 → 180 → 0).
> **Retirez les hélices** pendant tous les tests au banc.

### Capteur à ultrasons

| HC-SR04 | Carte |# DroneCode

Code embarqué d'un drone quadricoptère « fait maison » basé sur **ESP32**, piloté à distance depuis une page web via le Wi-Fi, avec retour vidéo en direct grâce à une **ESP32-CAM**.

> Projet en cours de développement : les briques matérielles sont testées séparément, le programme global (`essaiTestGlobal.ino`) n'est pas encore implémenté.

## Principe général

Le projet repose sur **deux microcontrôleurs** :

| Carte | Rôle |
|---|---|
| **ESP32-CAM** | Diffuse un flux vidéo via un serveur web |
| **ESP32** | Héberge la page de contrôle (IP locale) avec la vidéo, reçoit les commandes (requêtes HTTP `GET`) et pilote les 4 moteurs |

### Commandes prévues

Avancer, reculer, gauche, droite, rotation gauche, rotation droite, monter, descendre.

### Logique de mouvement

- **Avancer / reculer** : diminuer la vitesse des moteurs avant et augmenter celle des moteurs arrière (et inversement). Même principe pour **gauche / droite**.
- **Monter / descendre** : augmenter / diminuer la vitesse des 4 moteurs.
- **Rotation** : modifier la vitesse relative des moteurs tournant dans le sens horaire (CW) et antihoraire (CCW).

### Stabilisation et sécurité (prévu)

- **Gyroscope (MPU-6050)** : détecter la dérive (droite, gauche, avant, arrière) et compenser en accélérant/décélérant les moteurs concernés.
- **Capteur à ultrasons** : ralentir à l'approche d'un obstacle, puis faire du sur-place sous un seuil de distance.

### Améliorations envisagées

- Caméra montée sur un servomoteur (mouvement vertical).
- Remplacer les boutons (vitesse constante) par un joystick pour un contrôle proportionnel.

## Contenu du dépôt

| Fichier | Description |
|---|---|
| `essaiTestGlobal.ino` | Cahier des charges et squelette du programme global (commentaires de conception, `setup()`/`loop()` vides) |
| `esp32camStreamWebServer.ino` | Flux vidéo de l'ESP32-CAM via serveur web |
| `blinkWebServerEsp32.ino` | Test de l'ESP32 avec serveur web (contrôle d'une LED) |
| `mpuToEsp.ino` | Lecture du MPU-6050 (accéléromètre, gyroscope, température) sur l'ESP32 via I2C |
| `testMotor.ino` | Test d'un moteur brushless via un ESC |
| `UltrasonicSimple.ino` | Mesure de distance avec un capteur à ultrasons (HC-SR04 ou 3 broches) |
| `dossier/` | Ressources complémentaires |

## Matériel

- 1× ESP32 (contrôleur de vol + serveur web)
- 1× ESP32-CAM (streaming vidéo)
- 4× moteurs brushless + 4× ESC
- 1× module MPU-6050 (gyroscope / accéléromètre)
- 1× capteur à ultrasons (HC-SR04 ou équivalent)
- Batterie + répartiteur d'alimentation (power distributor)

## Câblage

### MPU-6050 → ESP32

| MPU-6050 | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SCL | GPIO 22 |
| SDA | GPIO 21 |
| INT | (optionnel) |

### ESC → carte

- Les 3 fils de l'ESC vers le moteur (intervertir 2 fils inverse le sens de rotation).
- `+` / `-` de l'ESC vers la batterie.
- Fil de signal (orange) vers une broche **PWM** (broche 9 dans `testMotor.ino`).
- Masse (GND) commune.

> Un ESC n'est opérationnel qu'après sa procédure d'initialisation (voir la notice du fabricant). `testMotor.ino` en effectue une basique (0 → 180 → 0).
> **Retirez les hélices** pendant tous les tests au banc.

### Capteur à ultrasons

| HC-SR04 | Carte |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal (`UltrasonicSimple.ino`) | broche 13 |

## Installation

1. Installer l'[Arduino IDE](https://www.arduino.cc/en/software).
2. Ajouter le support ESP32 : *Fichier → Préférences → URL de gestionnaire de cartes* puis installer **esp32** (Espressif) depuis le gestionnaire de cartes.
3. Installer les bibliothèques suivantes (gestionnaire de bibliothèques) :
   - `Adafruit MPU6050`
   - `Adafruit Unified Sensor`
   - `Adafruit BusIO`
   - `Ultrasonic` (Erick Simões)
   - `Servo` (pour `testMotor.ino`)
4. Cloner le dépôt :
```bash
   git clone https://github.com/PierreAlexandre13/DroneCode.git
```
5. Ouvrir le `.ino` voulu, choisir la carte et le port, puis téléverser.

## Utilisation

Chaque sketch est testable indépendamment. Ouvrez le moniteur série à la vitesse indiquée dans le code (`115200` pour le MPU-6050, `9600` pour les autres).

- **Flux vidéo** : téléverser `esp32camStreamWebServer.ino` sur l'ESP32-CAM, renseigner les identifiants Wi-Fi, puis ouvrir l'adresse IP affichée dans le moniteur série.
- **Capteur de distance** : `UltrasonicSimple.ino` affiche la distance en cm et « STOP » sous 50 cm.
- **Centrale inertielle** : `mpuToEsp.ino` affiche accélération, rotation et température toutes les 500 ms.


|---|---|
| VCC | 5V |
| GND | GND |
| Signal (`UltrasonicSimple.ino`) | broche 13 |

## Installation

1. Installer l'[Arduino IDE](https://www.arduino.cc/en/software).
2. Ajouter le support ESP32 : *Fichier → Préférences → URL de gestionnaire de cartes* puis installer **esp32** (Espressif) depuis le gestionnaire de cartes.
3. Installer les bibliothèques suivantes (gestionnaire de bibliothèques) :
   - `Adafruit MPU6050`
   - `Adafruit Unified Sensor`
   - `Adafruit BusIO`
   - `Ultrasonic` (Erick Simões)
   - `Servo` (pour `testMotor.ino`)
4. Cloner le dépôt :
```bash
   git clone https://github.com/PierreAlexandre13/DroneCode.git
```
5. Ouvrir le `.ino` voulu, choisir la carte et le port, puis téléverser.

## Utilisation

Chaque sketch est testable indépendamment. Ouvrez le moniteur série à la vitesse indiquée dans le code (`115200` pour le MPU-6050, `9600` pour les autres).

- **Flux vidéo** : téléverser `esp32camStreamWebServer.ino` sur l'ESP32-CAM, renseigner les identifiants Wi-Fi, puis ouvrir l'adresse IP affichée dans le moniteur série.
- **Capteur de distance** : `UltrasonicSimple.ino` affiche la distance en cm et « STOP » sous 50 cm.
- **Centrale inertielle** : `mpuToEsp.ino` affiche accélération, rotation et température toutes les 500 ms.

