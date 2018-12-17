# Joc matrice 8x8 Asteroid Storm

 Clase existente in program : 

## JoiceStick
	Clasa care se opereaza pe un modul joystick arduino. 
	Scop : ofera posibilitatea de a  seta functii care sa fie activate 
	cand joystick-ul ajunge in pozitie sus, jos, stanga sau dreapta. 


## Matrix8x8 

		Clasa care tine minte in vector de elemente de tip byte 
	cu operatori pe biti supraincarcati, functie de afisare pe matrice 
	(printr-un parametru de tip LedControl)
		Scop : ofera un model de lucru usor de modificat pentru 
	a fi afisat pe matricea de leduri 8x8

## De adugat toate descrierile claselor si mutat Updates in README-ul de mai sus

## Updates

### v0.4
	-adaugat clasele ShipLaser si Asteroids
	-rezolvat un bug in care nu-mi recunostea functiile de move ale clasei SpaceShip

### v0.5
	- inlocuit delay cu millis in clasa JoiceStick
	BUGS:	- ledurile licaresc
	

# MillisFix updates
### v1.1	
	-schimbat functia int checkDelay() in void checkDelay 
	-adaugat o variabila bool goodToGo
		-este true atunci cand se poate executa ceva
		-false cand inca nu a trecut timp mai mare sau egal cu delayTime de la ultima actiune
	-adaugat goodToGo un functiile checkHorizontal si checkVertical
		-flow control care permit si verificarea isX si isY daca a trecut destul timp
	BUGS:
		-tot licare...

### v1.2
	-adaugat in clasa JoiceStick doua metode
		-'isY with Delay' si 'check Horizontal with Delay'
		-nu folosesc millis ci delay dupa citirea valorii 
			analogice de la pin
	-schimbat metoda chemata de Ctrl in loop-ul din 
		AsteroidStorm.ino cu cea adaugata
	-nu mai licaresc LED-urile matricii

	-WTF
	
### v1.3
	-adaugat clasa PushButton
		-clasa care foloseste millis() pentru delay
	-adaugat clasa Laz in main
	-adaugat functii de tras proiectile pe 2 butoane
	Issues: -proiectilele nu mi misca destul de repede din cauza 
		delay-ului din clasa JoiceStick
	Idee: functia checkDelay trebuie pusa in interiorul if-ului care
		afirma ca un buton este apasat si trebuie sa execute 
		actiunea doar daca a trecut timpul necesar
### v1.4 
	-REZOLVAT PROBLEMA cu LED-urile care licare
	-adaugat verificarea delay-ului DUPA ce am citit directia data 
		de joystick si INAINTE de a chema functia respectiva
	-actualizat niste valori pentru delay-uri
	-sters metoda care folosesc functia delay()

### v1.5
	Terminat clasa asteroid
	-creat functie de generat 2^k pentru masca de biti
	-adaugat functie care genereaza asteroizi: *genField(short howMany)*
	Idee: 	Se genereaza intr-un byte atatia '1' cat se dau ca parametru.
			Se porneste cu B00000000. Se creeaza masca de putere random si se adauga bitul
				daca nu exista deja, adaugandu-se howMany biti.
			Pentru numere mai mici ca 4 se genereaza normal, pentru numere mai mari 
				se genereaza 8-howMany asteroizi apoi se neaga. Pentru 8 se returneaza 255.
	-functie care genereaza asteroizi in functie de dificultate 
	Idee: Sunt 3 dificultati: EASY, MEDIUM, HARD
			Pentru EASY se genereaza 2, 3 sau 4 asteroizi
			Pentru MEDIUM se genereaza 4, 5 sau 6 asteroizi
			Pentru HARD se genereaza 6, 7 sau 8 asteroizi
		Calculul pentru generat este : 2 + diff + rand
			unde diff e dificultatea cu valori intre 0 si 2
				rand e un numar random intre 1 si 3 (pentru diversitate)