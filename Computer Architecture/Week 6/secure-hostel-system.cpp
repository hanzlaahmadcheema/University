#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','='}
};

byte rowPins[rows] = {2, 3, 8, 9};
byte colPins[cols] = {A1, A2, A3, A4};

Keypad pad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

const int gLed = 12;
const int rLed = 13;
const int buzz = A0;

String pass = "";
String check = "";
const String def = "1234";

int tries = 0;
bool lock = false;
unsigned long lockTime = 0;
unsigned long last = 0;
int sec = 0;
int min = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(gLed, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);

  lcd.print(" Riphah International University");
  lcd.setCursor(0, 1);
  for(int i=0; i<16; i++) {
    lcd.scrollDisplayLeft();
    delay(500);
  }
  Serial.println("System Booting...");
  delay(1500);
  lcd.clear();
}

void loop() {
  unsigned long now = millis();

  if (now - last >= 1000) {
    last = now;
    sec++;
    if (sec >= 60) {
      sec = 0;
      min++;
    }
    showTime();
  }

  if (lock) {
    if (now - lockTime < 30000) {
      lcd.setCursor(0, 1);
      lcd.print("Locked 30s     ");
      return;
    } else {
      lock = false;
      tries = 0;
      lcd.clear();
      showTime();
      lcd.setCursor(0, 1);
      lcd.print("Enter Pass:");
    }
  }

  char key = pad.getKey();
  if (key) {
    Serial.print("Key: "); Serial.println(key);

    if (key >= '0' && key <= '9') {
      if (pass.length() < 4) {
        pass += key;
        lcd.setCursor(12 + pass.length() - 1, 1);
        lcd.print('*');
      }
    } else if (key == '=') {
      checkPass();
    } else if (key == '*') {
      pass = "";
      check = "";
      lcd.setCursor(0, 1);
      lcd.print("Enter Pass:    ");
    }
  }
}

void showTime() {
  lcd.setCursor(0, 0);
  lcd.print("2020-EE-123");
  if (min < 10) lcd.print("0");
  lcd.print(min);
  lcd.print(":");
  if (sec < 10) lcd.print("0");
  lcd.print(sec);
}

void checkPass() {
  static bool first = true;

  if (first) {
    check = pass;
    pass = "";
    first = false;
    lcd.setCursor(0, 1);
    lcd.print("Re-enter Pass: ");
  } else {
    if (pass == check && pass == def) {
      accessYes();
    } else {
      accessNo();
    }
    first = true;
    pass = "";
    check = "";
  }
}

void accessYes() {
  lcd.clear();
  lcd.print("Access Granted ");
  Serial.println("Access Granted!");
  digitalWrite(gLed, HIGH);
  delay(3000);
  digitalWrite(gLed, LOW);
  noTone(buzz);
  lcd.clear();
  showTime();
  lcd.setCursor(0, 1);
  lcd.print("Enter Pass:");
}

void accessNo() {
  lcd.clear();
  lcd.print("Access Denied  ");
  Serial.println("Access Denied!");
  for (int i = 0; i < 3; i++) {
    digitalWrite(rLed, HIGH);
    tone(buzz, 200, 200);
    delay(200);
    digitalWrite(rLed, LOW);
    delay(200);
  }
  noTone(buzz);
  tries++;

  if (tries >= 3) {
    lock = true;
    lockTime = millis();
    lcd.clear();
    lcd.print("Locked 30s");
    Serial.println("System Locked for 30s");
  } else {
    lcd.clear();
    showTime();
    lcd.setCursor(0, 1);
    lcd.print("Enter Pass:");
  }
}