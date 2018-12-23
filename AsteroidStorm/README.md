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
		Scop : ofera un camp de lucru usor de modificat pentru a simula
	comportamente iar mai apoi pentru a fi afisat pe matricea de leduri 8x8.

## MillisWait
	Clasa care se ocupa cu flow-control-ul conditionat de delay-uri. In termeni simpli, intarzie 
	anumite evenimente fara a ingheta executia intregului program.
	
	
## LeCeDe
	Clasa ce mosteneste clasa LiquidCristal si retine 2 siruri de lungime 17 
	(Lungimea unui rand LCD  + '\0') ce ofera metode de prelucare si afisare 
	a celor 2 siruri pe un display LCD.
	
## PushButton 
	Clasa ce se ocupa de comportamentul unui buton si executa o functie de tip void 
	fara parametrii atunci cand acesta este apasat, in functie de un delay.
	
## SpaceShip 
	Clasa descendenta din Matrix8x8 ce simuleaza o naveta pe ultimele 2 linii
	ale acesteia si contine functii de miscare care o restrictioneaza la 
	dimensiunile matricei.
	Consista din masca modelul navetei si pozitiile armelor, memorate in 2 
	elemente de tip byte ce sunt actualizate o data cu miscarile matricei. 
	O functie importanta a acestei clase este functie didCollide(bool&,Matrix8x8&)
	care verifica suprapunerea navetei cu o alta matrice, scriind 'true'
	in parametrul de tip bool in caz afirmativ.
	
## ShipLaser
	Clasa descendenta din Matrix8x8 ce simuleaza laserele trase de naveta.
	Consista dintr-un element de tip byte ce simuleaza liniile ce au lasere,
	2 elemente de tip MillisWait (unul pentru intervalul de tip intre care se 
	pot trage 2 lasere si unul pentru penalizare). Metodele principala sunt 
	void update() (ce shifteaza in sus matricea atunci cand laserTracker nu e 0)
	si void contact(Matrix8x8&,int&) care creste elementul de tip int atunci cand 
	elementele intra in contact cu elementele altei matrici, stergandu-le pe 
	ambele dupa.

## Asteroids
	Clasa descendenta din Matrix8x8 ce simuleaza un camp de asteroizi. Consista din 
	doua elemente de tip short ce reprezinta dificultatea si viteza de deplasare.
	Dificultatea consta in numarul de asteroizi generati (usor - 2,3,4; mediu - 4,5,6;
	greu - 6,7,8) iar viteza repezinta delay-ul in functie de care se misca.
	Metodele principale sunt byte genField (short howMany) ce genereaza o linie 
	de 'howMany' asteroizi pozitionati aleator si metoda addMeteors(bool&) ce adauga
	asteroizi in functie de dificultatea selectata si modifica bool-ul transmis ca parametru
	daca exista asterozi ce ies din matrice.
	
	TIP: muta metoda didCollide in asteroizi ca sa se ocupa doar ei de decizia termianrii
	unei runde
	
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
### v1.6
	-adaugat clasa LeCeDe

### v1.7
	-clasa asteroizi + collide laser
	-functie adunat punctaj
	
### v1.8
	-actualizat pini pentru compatibilitate Arduino NANO
	
### v1.9
	-Matrice si Display simultan

### v2.0
	-prezentabil dar nu merge calumea
	-dificultate creste o data cu timul
	-separat pe stari de joc
	-alte..

### v2.1
	-restructurat functia loop 
		-am introdus variabilele myMenu, gameOver si outOfLives 
		pentru flow control
	-rezolvat un bug in care imi executa 2 comenzi diferite ale
		aceluiasi buton in 2 iteratii diferite ale functiei loop 
		(cu un delay)
	-scos toate serial-urile din program

### v2.2
	-am modificat delay-ul laserelor la 190 ms
	-sters comenatarii inutile
	-actualizat program pentru a folosi doar 2 variabile de tip
		PushButton