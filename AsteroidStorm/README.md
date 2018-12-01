# Joc matrice 8x8 Asteroid Storm

## Clase existente in program : 

### JoiceStick
	Clasa care se opereaza pe un modul joystick arduino. 
	Scop : ofera posibilitatea de a  seta functii care sa fie activate 
cand joystick-ul ajunge in pozitie sus, jos, stanga sau dreapta. 


### Matrix8x8 

	Clasa care tine minte in vector de elemente de tip byte cu 
operatori pe biti supraincarcati, functie de afisare pe matrice 
(printr-un parametru de tip LedControl)
	Scop : ofera un model de lucru usor de modificat pentru a fi 
afisat pe matricea de leduri 8x8


v0.4
	-am adaugat clasele ShipLaser si Asteroids
	-rezolvat un bug in care nu-mi recunostea functiile de move ale clasei SpaceShip

v0.5
	- inlocuit delay cu millis in clasa JoiceStick
BUGS: 
	- ledurile licaresc