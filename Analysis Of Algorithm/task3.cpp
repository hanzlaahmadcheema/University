  #include <Keypad.h>
  #include <LiquidCrystal.h>


  LiquidCrystal lcd(10, 11, 4, 5, 6, 7);


  const byte ROWS = 4; 
  const byte COLS = 4; 
  char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','='}
  };
  byte rowPins[ROWS] = {2, 3, 8, 9};   
  byte colPins[COLS] = {A1, A2, A3, A4};

  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


  const int greenLED = 12;
  const int redLED = 13;
  const int buzzer = A0;


  String enteredPass = "";
  String confirmPass = "";
  const String defaultPass = "1234";

  int attempts = 0;
  bool locked = false;
  unsigned long lockStart = 0;
  unsigned long prevMillis = 0;
  int seconds = 0;
  int minutes = 0;


  void setup() {
    lcd.begin(16, 2);
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);

    lcd.print(" Riphah International University");
    lcd.setCursor(0, 1);
    for(int x=0; x<16; x++) {
    lcd.scrollDisplayLeft();
    delay(500);
    }
    Serial.println("System Booting...");
    delay(1500);
    lcd.clear();
  }


  void loop() {
    unsigned long currentMillis = millis();


    if (currentMillis - prevMillis >= 1000) {
      prevMillis = currentMillis;
      seconds++;
      if (seconds >= 60) {
        seconds = 0;
        minutes++;
      }
      displayClock();
    }


    if (locked) {
      if (currentMillis - lockStart < 30000) {
        lcd.setCursor(0, 1);
        lcd.print("Locked 30s     ");
        return;
      } else {
        locked = false;
        attempts = 0;
        lcd.clear();
        displayClock();
        lcd.setCursor(0, 1);
        lcd.print("Enter Pass:");
      }
    }


    char key = keypad.getKey();
    if (key) {
      Serial.print("Key Pressed: "); Serial.println(key);

      if (key >= '0' && key <= '9') {
        if (enteredPass.length() < 4) {
          enteredPass += key;
          lcd.setCursor(12 + enteredPass.length() - 1, 1);
          lcd.print('*');
        }
      } else if (key == '=') {
        handlePassword();
      } else if (key == '*') {
        enteredPass = "";
        confirmPass = "";
        lcd.setCursor(0, 1);
        lcd.print("Enter Pass:    ");
      }
    }
  }



  void displayClock() {
    lcd.setCursor(0, 0);
    lcd.print("2020-EE-123");
    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");
    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
  }

  void handlePassword() {
    static bool firstEntry = true;

    if (firstEntry) {
      confirmPass = enteredPass;
      enteredPass = "";
      firstEntry = false;
      lcd.setCursor(0, 1);
      lcd.print("Re-enter Pass: ");
    } else {
      if (enteredPass == confirmPass && enteredPass == defaultPass) {
        accessGranted();
      } else {
        accessDenied();
      }
      firstEntry = true;
      enteredPass = "";
      confirmPass = "";
    }
  }

  void accessGranted() {
    lcd.clear();
    lcd.print("Access Granted ");
    Serial.println("Access Granted!");
    digitalWrite(greenLED, HIGH);
    delay(3000);
    digitalWrite(greenLED, LOW);
    noTone(buzzer);
    lcd.clear();
    displayClock();
    lcd.setCursor(0, 1);
    lcd.print("Enter Pass:");
  }

  void accessDenied() {
    lcd.clear();
    lcd.print("Access Denied  ");
    Serial.println("Access Denied!");
    for (int i = 0; i < 3; i++) {
      digitalWrite(redLED, HIGH);
      tone(buzzer, 200, 200);
      delay(200);
      digitalWrite(redLED, LOW);
      delay(200);
    }
    noTone(buzzer);
    attempts++;

    if (attempts >= 3) {
      locked = true;
      lockStart = millis();
      lcd.clear();
      lcd.print("Locked 30s");
      Serial.println("System Locked for 30s");
    } else {
      lcd.clear();
      displayClock();
      lcd.setCursor(0, 1);
      lcd.print("Enter Pass:");
    }
  }