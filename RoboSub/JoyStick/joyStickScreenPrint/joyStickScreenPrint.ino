// #define location of pins
//this is kimberly testing what happens when I edit the code on the GitHub page.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);


#define SW1 1 //joystick one
#define SW2 2 //joystick one
int joystick1_x = A0; //joystick one x = JS1 VRx
int joystick1_y = A1; //joystick one y = JS1 VRy
int joystick2_x = A3; //joystick two x = JS2 VRx
int joystick2_y = A4; //joystick two y = JS2 VRy
//NANO A2 and A7 are buttons
//analog is a slidy light switch, digital is on or off

int pos1_x;
int pos1_y;
int pos2_x;
int pos2_y;

//0-1023, 0 is left or up, 1023 is right or down.
//Serial.print(variable) prints that variable to the computer!
//lcd.print(variable) will print to the lcd screen
  
// Initialize Variables:
int xVal = 0;
  // You will need to initialize yVal, too.


/* Sets up the pins as inputs or outputs */
void setup() {
  Serial.begin(9600);
  //lcd.begin(16,2);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  //lcd.init();
  //lcd.backlight();
  /* You will need to initialize led_bPin as an OUTPUT, and joy_xPin + joy_yPin as INPUT s*/
}


/* This function is called on endless repeat. The main code goes here. */
void loop() {
  pos1_x = analogRead(joystick1_x);
  pos1_y = analogRead(joystick1_y);
  pos2_x = analogRead(joystick2_x);
  pos2_y = analogRead(joystick2_y);
  Serial.print("JS 1 X: ");
  Serial.println(pos1_x);
  Serial.print("JS 1 Y: ");
  Serial.println(pos1_y);
  Serial.print("JS 2 X: ");
  Serial.println(pos2_x);
  Serial.print("JS 2 Y: ");
  Serial.println(pos2_y);
  Serial.println();
  /*lcd.setCursor(0,0);
  lcd.print("JS1 x, y ");
  lcd.print(pos1_x);
  lcd.print(pos1_y);
  lcd.setCursor(0,1);
  lcd.print("JS2 x, y ");
  lcd.print(pos2_x);
  lcd.print(pos2_y);*/
  delay(4500);

  /*Update xVal and yVal using the command 'analogRead(pin)', with 'pin' being one of the #defined pins.
    
    For both xVal and yVal, if the value is greater than joyHigh or lower than joyLow,
      turn on either the red or blue LED (use command 'digitalWrite(pin, HIGH)'
      to send power to a pin, and LOW to stop sending power)
  */
 
}
