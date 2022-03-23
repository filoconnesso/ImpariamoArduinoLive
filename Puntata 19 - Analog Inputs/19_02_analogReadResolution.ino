/*****************************************************************
 *               revisione sketch by Petenatti P.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #19                  *  
 *                     Analog inputs e pwm                       * 
 *                 https://youtu.be/P1OLH0sSmw4                  *        
 *                                                               *
 *****************************************************************
 *              analogRead Resolution 00:52:20                   *
 *                                                               *
 *****************************************************************
 */

// indico che il fotoresistore è collegato su A2
#define PHOTORESISTOR A2

// inizializzo la varibile
int val = 0;

void setup() {
  Serial.begin(115200);
  
  // imposto la risoluzione dell'ADC a 12 o 16 bit 
  analogReadResolution(12);
  //analogReadResolution(16);
}

void loop() {
  // leggo il valore analogico e lo assegno a "val"
  val = analogRead(PHOTORESISTOR);
  // e lo scrivo sul serial monitor
  Serial.println(val);
  
  delay(400);

}
