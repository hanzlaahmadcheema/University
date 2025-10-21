int a;   

void setup() {
  Serial.begin(9600);                
  Serial.println("Enter a decimal number:");
  while (Serial.available() == 0);   
  a = Serial.parseInt();             
  Serial.print("Binary: ");
  Serial.println(a, BIN);            
  Serial.print("Hexadecimal: ");
  Serial.println(a, HEX);            
}

void loop() {
  
}