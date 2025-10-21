int led = 2;

void setup() {
  pinMode(led, OUTPUT);

  for (int i = 0; i < 2; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}

void loop() {}