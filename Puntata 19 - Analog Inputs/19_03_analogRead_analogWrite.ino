/*****************************************************************
 *               revisione sketch by Petenatti P.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #19                  *  
 *                     Analog inputs e pwm                       * 
 *                 https://youtu.be/P1OLH0sSmw4                  *        
 *                                                               *
 *****************************************************************
 *      uso di analogRead insieme a analogWrite  01:01:35        *
 *                                                               *
 *****************************************************************
 */
 
// indico che il fotoresistore è collegato su A2
#define PHOTORESISTOR A2
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
