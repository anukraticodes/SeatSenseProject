#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Pin definitions for sensors and LCD
const int sens1 = 2; // Example digital pin number for sensor 1 (replace with actual pin numbers)
const int sens2 = 6; // Example digital pin number for sensor 2 (replace with actual pin numbers)
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// WiFi credentials
const char* ssid = "MY";
const char* password = "asdfghjkl";

// Firebase credentials
const char* firebaseHost = "seatsense-d9f3f-default-rtdb.firebaseio.com";
const char* firebaseAuth = "CTnrbpt08vJgMbjuNRTXuRZRNcoYQUk1gGKqZ79";

// Maximum seat capacity and current count
const int max_seat = 40;
int curr = 0;

void setup() {
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  Serial.begin(9600);
  lcd.backlight();
  lcd.init(); // initialize the lcd

  // Connect to WiFi
  connectToWiFi();

  // Initialize Firebase
  Firebase.begin(firebaseHost, firebaseAuth);
}

void loop() {
  // Read sensor inputs
  int in = digitalRead(sens1);
  int out = digitalRead(sens2);

  // Update current seat count based on sensor inputs
  if (in == LOW && curr < max_seat) {
    curr++;
  }

  if (out == LOW && curr > 0) {
    curr--;
  }

  // Print seat count to Serial Monitor
  Serial.print("Number of vacant seats: ");
  int vac = max_seat - curr;
  Serial.println(vac);

  // Print seat count to LCD
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Number of = ");
  lcd.print(vac);
  lcd.setCursor(0, 1);
  lcd.print("vacant seats");

  // Upload data to Firebase
  Firebase.setInt("seat_count", vac);

  delay(1000); // Adjust delay as needed
}

void connectToWiFi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
