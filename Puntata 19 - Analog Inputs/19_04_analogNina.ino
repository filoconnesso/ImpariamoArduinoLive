/*****************************************************************
 *               revisione sketch by Petenatti P.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #19                  *  
 *                     Analog inputs e pwm                       * 
 *                 https://youtu.be/P1OLH0sSmw4                  *        
 *                                                               *
 *****************************************************************
 *      usare pin analogici da A4 a A7   01:27:20                *
 *                                                               *
 *****************************************************************
 */
// per poter utilizzare i pin analogici da A4 a A7 devo includere la libreria
// WiFiNINA.h, perchè questi pin sono collegati al chip NINA W102 e non direttamente
// sul microcontrollore RP2040

#include <WiFiNINA.h>
// indico che il fotoresistore è collegato su A6
#define PHOTORESISTOR A6
 // indico che il led è collegato sul pin 13
#define LED 13

// inizializzo la varibile
int val = 0;

void setup() {
  Serial.begin(115200);

  // imposto la risoluzione in lettura a 12bit
  analogReadResolution(12);
  // imposto la risoluzione in scrittura a 12bit
  analogWriteResolution(12);
    
}

void loop() {
  // leggo il valore analogico e lo assegno a "val"
  val = analogRead(PHOTORESISTOR);
  // imposto lo stesso valore all'uscita
  analogWrite(LED, val);
  // e lo scrivo sul serial monitor
  Serial.println(val);
  
  delay(50);

}
