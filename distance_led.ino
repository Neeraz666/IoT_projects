// C++ code
//
int led = 3;
int trig = 5;
int echo = 7;

int distance;
int pingTravelTime;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  pingTravelTime = pulseIn(echo, HIGH);
  
  distance = (pingTravelTime/2) * 0.0343;
    
  if (distance > 20) {
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led,HIGH);
  }    
  
}
