int a, b, c;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter first number:");
  while (Serial.available() == 0);
  a = Serial.parseInt();             

  Serial.println("Enter second number:");
  while (Serial.available() == 0);
  b = Serial.parseInt();             

  c = a + b;                         

  Serial.print("Sum in Hexadecimal: ");
  Serial.println(c, HEX);
  Serial.print("Sum in Binary: ");
  Serial.println(c, BIN);
}

void loop() {
  
}