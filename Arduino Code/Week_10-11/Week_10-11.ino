void setup() {
  Serial.begin(9600);

}

void loop() {
int analogValue = analogRead(A0);

Serial.print("Light Reading = ");
Serial.print(analogValue);
Serial.println(" ");


}
