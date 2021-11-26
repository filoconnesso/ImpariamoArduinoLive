int arr[] = {2,4,6,20,43};

void arrayExploder(int myArr[], int numElements) {
  for(int i = 0; i < numElements; i++)  {
    Serial.println(myArr[i]);
  }
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  arrayExploder(arr, 5);
}

void loop() {
  

}
