/*****************************************************************
 *               revisione sketch by Petenatti P.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #19                  *  
 *                     Analog inputs e pwm                       * 
 *                 https://youtu.be/P1OLH0sSmw4                  *        
 *                                                               *
 *****************************************************************
 *                     analogRead   00:37:30                     *
 *                                                               *
 *****************************************************************
 */
 
// indico che il fotoresistore è collegato su A2
#define PHOTORESISTOR A2

// inizializzo la varibile
int val = 0;

void setup() {
  Serial.begin(115200);

}

void loop() {
  // leggo il valore analogico e lo assegno a "val"
  val = analogRead(PHOTORESISTOR);
  // e lo scrivo sul serial monitor
  Serial.println(val);

  delay(400);

}
