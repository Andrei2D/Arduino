# GoodGameBoi
    Proiect final al optionalului de Arduino. Acesta consista dintr-o consola de mini-game-uri pentru matrice 8x8

## Updates:

### v0.1 - Initial commit
    * Am importat clasele MillisWait, LeCeDe, JoiceStick, PushButton, Matrix8x8, SpaceShip, ShipLasers, Asteroids din proiectul ASteroidStorm 
    * Urmeaza a fi modificate si adaptate pentru multifunctionalitate in mai multe jocuri

### v0.2 - Working restructuration
    * Modificarile din urma proiectului anterior au fost testate 
    * Am rezolvat niste erori mici

### v0.3 - Analog push buttons
    * Creat clasa AlgPushButton pentru butoane ce sunt conectate la pinii analogici, astfel economisind pini digitali
    * Exista 2 tipuri : 
            -buton clasic, pentru care functia isPressed() returneaza true daca de la pin se citeste 1020 (sau valori peste 900)
            -buton joystick, pentru care functia isPressed() returneaza true daca se citeste 0 (ori valori sub 10)
