#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int sens1 = 2;
int sens2 = 12;
int max_seat = 40;
int curr = 15;

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);              // start serial communication at 9600 baud
  Serial.println("Serial Monitor is working!"); // print a test message
}

void loop() {
  int in = digitalRead(sens1);
  int out = digitalRead(sens2);

  lcd.clear();
  if (in == LOW) { // assuming LOW means sensor is triggered
    if (curr < max_seat) {
      curr++;
    }
  }

  if (out == LOW) { // assuming LOW means sensor is triggered
    if (curr > 0) {
      curr--;
    }
  }

  // Print to Serial
 
  Serial.println("Number of vacant seats: ");
  Serial.println(max_seat - curr);

  // Print to LCD
  lcd.setCursor(0, 0);
  lcd.print("Vacant seats: ");
  lcd.print(max_seat - curr);
  
  delay(1000); // Wait for a second before the next loop iteration
}