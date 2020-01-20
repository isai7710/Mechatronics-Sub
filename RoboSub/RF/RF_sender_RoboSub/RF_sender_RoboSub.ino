#include <RH_ASK.h>             //Setup for 433 module
#include <SPI.h>                // Not actually used but needed to compile
#include <Wire.h>              

// Make sure that the sender pin is on pin 12 on this arduino

RH_ASK driver; //Required

#define SW1 1                     //joystick 1 button
#define SW2 2                    //joystick 2 button

int joystick1_x = A0;              // joystick1 x direction pin                                         
int joystick1_y = A1;              // joystick1 y direction pin                                    
int pos_x;                   // declaring variable to store horizontal value joystick 1
int pos_y;                   // declaring variable to store vertical value joystick 1
int high_x1 = 600;           // 400-600 is the range where the joystick can be zero
int low_x1 = 400;
int high_y1 = 600;
int low_y1 = 400;
String str_command;         // this tells us the direction and motion
String str_amount;          // this tells us how much in a certain direction or motion
String str_out;             // combines command and amount

void setup() {
  Serial.begin (9600);      // allows serial communication
  pinMode(SW1, INPUT_PULLUP);     //Define pins
  pinMode(SW2, INPUT_PULLUP);

  if (!driver.init())                     //Setup for 433 module
         Serial.println("init failed");
}

/*
str_command:
10 - straight
11 - left
12 - right
13 - forward
14 - backward
15 - stop
*/

void loop() {

  pos_x = analogRead (joystick1_x) ;     //Read values from joystick 1
  pos_y = analogRead (joystick1_y) ;

  //-------Steering (left and right)-------


      //----------checking horizontal values-------------
      //----------LEFT--------------
      if (pos_x < low_x1)   // checks thresholds                  
        {
            //Send left command to let receiver know what to expect
            str_command = "11";

            //Find amount of force in left direction
            int xleft = map(pos_x, 400, 0, 0, 150);  // we use 150 because that is the highest PWM signal the DC motor can work on
            xleft = xleft + 100;  // we need 6 characters to send. This makes it so that 

            //convert xleft to a string
            str_amount = String(xleft);

            //combine command and amount
            str_out = str_command + "," + str_amount;
            Serial.print("LEFT");
            Serial.println(str_amount);

            static char *msg = str_out.c_str();

            driver.send((uint8_t *)msg, strlen(msg));
            driver.waitPacketSent();

            xleft = 0;

            delay(100); // IMPORTANT: always put some type of delay here
        }

       //-----------RIGHT------------
      else if (pos_x > high_x1)
        {
            //Send right command to let receiver know what to expect
            str_command = "12";

            //Find amount of force in right direction
            int xright = map(pos_x, 600, 1023, 0, 150);
            xright = xright + 100;

            //convert xright to a string
            str_amount = String(xright);

            //combine command and amount
            str_out = str_command + "," + str_amount;
            Serial.print("RIGHT");
            Serial.println(str_amount);

            static char *msg = str_out.c_str();

            driver.send((uint8_t *)msg, strlen(msg));
            driver.waitPacketSent();

            xright = 0;

            delay(100);
        }
        //---------STRAIT----------
       else
         {
            //Send straight command to let receiver know what to expect
            str_command = "10";

            //Set amount of force in right or left direction as zero
            int xstraight = 0;
            xstraight = xstraight + 100;

            //convert xright to a string
            str_amount = String(xstraight);

            //combine command and amount
            str_out = str_command + "," + str_amount;
//            Serial.print("STRAIT");
//            Serial.println(str_amount);

            static char *msg = str_out.c_str();

            driver.send((uint8_t *)msg, strlen(msg));
            driver.waitPacketSent();

            xstraight = 0;

            delay(100);
         }

// ----------Motion (forward and backward) -------


      //------FORWARD----------
      //--------checking vertical values------------     
      if (pos_y < low_y1)                         
        {
          //Send forward command to let receiver know what to expect
          str_command = "13";

          //Find amount of force in forward direction
          int yfor = map(pos_y, 400, 0, 0, 150);
          yfor = yfor + 100;               

          //convert yup to a string
          str_amount = String(yfor);

          //combine command and amount
          str_out = str_command + "," + str_amount;
          Serial.print("FORWARD");
          Serial.println(str_amount);

          static char *msg = str_out.c_str();

           driver.send((uint8_t *)msg, strlen(msg));
           driver.waitPacketSent();

           yfor = 0;

           delay(100);
        }

      //-------BACKWARD-------- 
      else if (pos_y > high_y1)
        {
          //Send backward command to let receiver know what to expect
          str_command = "14";

          //Find amount of force in backward direction
          int yback = map(pos_y, 600, 1023, 0, 150);   
          yback = yback + 100; 

          //convert ydown to a string
          str_amount = String(yback);

          //combine command and amount
          str_out = str_command + "," + str_amount;
          Serial.print("BACKWARD");
          Serial.println(str_amount);

          static char *msg = str_out.c_str();

           driver.send((uint8_t *)msg, strlen(msg));
           driver.waitPacketSent();

           yback = 0;

           delay(100);
        }

       //------------STOP----------
       else
         {
          //Send stop command to let receiver know what to expect
          str_command = "15";

          //Set amount of force in forward or backward direction as zero
          int ystop = 0;
          ystop = ystop + 100;

          //convert ystop to a string
          str_amount = String(ystop);

          //combine command and amount
          str_out = str_command + "," + str_amount;
//          Serial.print("STOP");
//          Serial.println(str_amount);

          static char *msg = str_out.c_str();

          driver.send((uint8_t *)msg, strlen(msg));
          driver.waitPacketSent();

          ystop = 0;

          delay(100);
         }
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
