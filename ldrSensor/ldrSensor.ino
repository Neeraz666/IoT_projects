int ledPin = 13;
int ldrInp = A1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrInp, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrInp);

  Serial.println(ldrValue);

  if (ldrValue < 20)
  {
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
