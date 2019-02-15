#ifndef MILLISWAIT_H

#define MILLISWAIT_H
#include <Arduino.h>

/*
    Clasa folosita pentru delay-urile inputurilor.
    Fiecare alta clasa care are principiul de periodicitate
        are declarat un obiect al acestei clase

*/
class MillisWait
{
    static unsigned long currentTime;   //Valoare curenta a millis 
    unsigned long lastTime;             //Valoare millis de la ultima verificare a delay-ului
    unsigned long theDelay;             //Delay-ul propriu zis ce trebuie asteptat
public:
    MillisWait ();
    MillisWait (unsigned long aDelay);
    void setDelay (unsigned long aDelay);
    static void readTime();
    bool isOk ();
};
/*
    Metoda readTime este chemata la inceputul functiei loop. Astfel
        functia millis nu este folosita la fiecare verificare a delay-ului.
    Metoda isOk este verifica daca a trecut timpul din delay si actualizeaza
        variabila lastTime
*/

#endif ///MILLISWAIT_H