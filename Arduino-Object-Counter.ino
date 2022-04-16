//Digital Object Counter

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int IRPin = 2;
int buzzerPin = 3;
int buttonPin = 4;

int n = 0;
int oldValue = 1;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  pinMode(IRPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0, 0);
  lcd.print("Count : ");

  if (digitalRead(IRPin) == 0 && oldValue == 1) {
    oldValue = 0;
    Count();
  } else if (digitalRead(IRPin) == 1 && oldValue == 0) {
    oldValue = 1;
  }

  if (digitalRead(buttonPin) == 0) {
    Reset();
  }

  delay(100);
}

void Count() {
  n = n + 1;

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(n);

  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}


void Reset() {
  n = 0;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(n);
}
