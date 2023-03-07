/// C++ code
//
#include <Servo.h>


Servo myservo;  // create servo object to control a servo
#define DELAYTIME 50 // How long each step takes
#define SERVOHOME 93 // Staring pos of the servo
#define OPENPOS 80 // the open pos of the servo
#define CLOSEDPOS 100 // the closed pos of the servo
// ------------------------------------------------------------
// Globals
// ------------------------------------------------------------
int stepAmount;
int pos = SERVOHOME;    // variable to store the servo position
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, INPUT);  // input from robot
  pinMode(10, OUTPUT); // output to servo
  digitalWrite(2, HIGH); 
  digitalWrite(10, HIGH);
  pos = myservo.read();
}

void loop() {
  if ( digitalRead(2) == HIGH && pos != CLOSEDPOS){ // checks if there is a signal and if there is moves towards the closed pos
      if(pos > CLOSEDPOS) // checks which way to go
       {
        stepAmount = 1;
       }
       else if(pos < CLOSEDPOS)
       {
         stepAmount = -1;
       }
       pos -= stepAmount;
      myservo.write(pos);              // tell servo to go to position in variable 'pos'  
      delay(DELAYTIME);  // waits
            
    }
    
  if(digitalRead(2) == LOW && pos && pos != OPENPOS){ // checks if there is not a signal and if there is moves towards the open pos
        if(pos > OPENPOS) // checks which way to go
        {
         stepAmount = 1;
        }
        else if(pos < OPENPOS)
        {
         stepAmount = -1;
        }
        pos -= stepAmount;
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(DELAYTIME);  // waits
      }
   if (digitalRead(2) == HIGH )
      {
        if (pos == CLOSEDPOS)
          {
        
            digitalWrite(10, HIGH); // turns on a return signal when finished
               
          }
        else
          {
            digitalWrite(10, LOW);
          }
               
      }
    else if(digitalRead(2) == LOW)
      {
      if (pos == OPENPOS)
          {
        
            digitalWrite(10, LOW); // turns on a return signal when finished
               
          }
        else
          {
            digitalWrite(10, HIGH);
          }
      }
    
    }
  
  
