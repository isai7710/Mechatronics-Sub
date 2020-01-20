#include <RH_ASK.h>         //433 module setup
#include <SPI.h>
#include <Wire.h>     

// Make sure that the receiver pin is on pin 11 on this arduino

RH_ASK driver;

String str_out;
String str_command;
String str_amount;
int command = 0;
int amount = 0;
int reset = 000;
int motor_speed = 0;

void setup() {
  Serial.begin(9600);

  if (!driver.init())
        Serial.println("init failed");     

}

void loop()
{
  uint8_t buf[6];   //Adjust this number to match the size of message you expect to receive
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
    {
       // Message with a good checksum received
      str_out = String((char*)buf);
      Serial.println(str_out);
  
      //split string into two values
      for (int i = 0; i < str_out.length(); i++)
        {
          if (str_out.substring(i, i+1) == ",")
            {
              str_command = str_out.substring(0, i);
              str_amount = str_out.substring(i+1);
            }
  
        }
            command = str_command.toInt();    //Turn the string command into an int
            amount = 0;
            amount = str_amount.toInt();
            str_amount = String(reset);
            motor_speed = amount - 100;
  
    }

//   Serial.println(amount);
//   Serial.println(motor_speed);
   if (amount >= 0)
   {

     switch (command)
            {
              case 10:
                Serial.print("Straight:");
                Serial.println(motor_speed);
                break;
              case 11:
                Serial.print("Left:");
                Serial.println(motor_speed);
                 break;
              case 12:
                Serial.print("Right:");
                Serial.println(motor_speed);
                break;
              case 13:
                Serial.print("Forward:");
                Serial.println(motor_speed);
                break;
              case 14:
                Serial.print("Backward:");
                Serial.println(motor_speed);
                break;
              case 15:
                Serial.print("Stop:");
                Serial.println(motor_speed);
                break;
              default:
                //Serial.println("Something is wrong!");
                break;
            }
     }

    else{}


}
