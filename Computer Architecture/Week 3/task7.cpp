#define led 2
int n;
float td = 1;   

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  Serial.println("How many times to blink?");
  while (Serial.available() == 0);     
  n = Serial.parseInt();               

  blinkLED(n, td);                     
}

void loop() {}

void blinkLED(int times, float delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(led, HIGH);
    delay(delayTime * 1000);
    digitalWrite(led, LOW);
    delay(delayTime * 1000);
  }
}
