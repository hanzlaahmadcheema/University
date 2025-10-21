int led = 2;
int n = 5;

void setup() {
  pinMode(led, OUTPUT);
  blinkLED(n);          
}

void loop() {}

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}
