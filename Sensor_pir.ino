const int PinBuzzer = 9;
const int LEDPin= 13;
const int PIRPin= A0;
void setup(){
pinMode(PIRPin, INPUT);
pinMode(LEDPin, OUTPUT);
pinMode(PinBuzzer, OUTPUT); 
}
void loop(){

int value= digitalRead(PIRPin);
 
  if (value == HIGH)
  {
    digitalWrite(LEDPin, HIGH);
    digitalWrite(PinBuzzer, HIGH);
    delay(5000);
    digitalWrite(LEDPin, LOW);
    digitalWrite(PinBuzzer, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
    digitalWrite(LEDPin, LOW);
    digitalWrite(PinBuzzer, LOW);
  }
}
