
const int led = 4;


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);


long duration;
double distance;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  //pri
  #define Green_led 11
  #define Blue_led 12
  #define Yellow_led 10
  #define White_led 13
  #define triggerPin 9
  #define echoPin 8
  
  
  pinMode(triggerPin, OUTPUT); //Define I/O Pins 
  pinMode(echoPin, INPUT);
  pinMode(Green_led, OUTPUT);
  pinMode(Blue_led, OUTPUT);
  pinMode(Yellow_led, OUTPUT);
  pinMode(White_led, OUTPUT);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  //string str = "hello world";
  lcd.setCursor(0,0);
  //lcd.print("helllllo world");
  delay(3000);
  
  for(int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
      lcd.print(i);
    lcd.setCursor(i, 1);
      for(int j = 0; j < 16; j++) {
        lcd.setCursor(j, 1);
        lcd.print(" ");
      }
      lcd.setCursor(i, 1);
      lcd.print("hello world");
      delay(500);
  }
  
digitalWrite(led, HIGH);
delay(500);
digitalWrite(led, LOW);
delay(500);
}
  
