/****************************************************************
 *               revisione sketch by Concetto G.                *
 ****************************************************************
 *                         Filo Connesso                        *
 *                   Impariamo Arduino Live #16                 *
 *          millis, micros, delay e delayMicroseconds           *
 *          https://www.youtube.com/watch?v=nqL65fmKfSA         *
 *                                                              *
 *      1.      Reference Arduino -  Time       00:08:50        *
 *      2.      delay()                         00:13:20        *
 *      3.      millis()                        00:26:55        *
 *      4.      micros()                        01:00:15        *
 *      5.      delayMicroseconds()             01:03:05        *
 *      6.      Discord                         01:07:53        *
 *                                                              *
 ****************************************************************
*/


//  -----------------> 4. micros() <-------------------

// in questo esempio sono state sostituite tutte le funzioni millis(), la cui impostazione è in millisecondi 1s 0 1000ms, con micros() dove il tempo è impostato in microsecondi 1s = 1000ms = 1000000us e si comporta in modo identico come nell'esempio 16c

#define LED 13    
bool status = false;    

unsigned long tempoAttuale, tempoPrecedente, tempoPrecedente1 = micros();
unsigned long timer = 1000000;

unsigned long timer1 = 3000000;

void setup() { 
	Serial.begin(115200);
    pinMode(LED, OUTPUT);
	tempoPrecedente = micros();
    tempoPrecedente1 = micros();
}

void loop() {
    tempoAttuale = micros();
    if((unsigned long) tempoAttuale - tempoPrecedente >= timer){
        tempoPrecedente = tempoAttuale;
        digitalWrite(LED, status);
        status = !status;
    }

    if((unsigned long) tempoAttuale - tempoPrecedente1 >= timer1){
        tempoPrecedente1 = tempoAttuale;
        Serial.println("test");
    }
	
//  -----------------> 5. delayMicroseconds() <-------------------

   	delayMicroseconds(5);
}