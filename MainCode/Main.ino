#include <Servo.h>

int mFWD = 2; // MOTOR ATTACHED TO PORT 2
int mBWD = 3; // MOTOR ATTACHED TO PORT 3
Servo servo;  // CREATING THE SERVO OBJECT;

/*----------------
  GLOBAL SETTINGS
-----------------*/

// TIMING
int tFB = 500;
int tLR = 500;

// DIRECTION DEGRESS #DO NOT CHANGE UNLESS YOU REBUILD THE RC CAR#
int tLFT = 110;
int tRGT = 50;
int ALGN = 80;

// LIGHTS
int flPin = 5;
int blPin = 10;

void setup()
{

  servo.attach(4);          // SERVO IS DEFINED TO THE PORT Nº10;
  servo.write(ALGN);        // STARTING SERVO WITH ALIGNED DIRECTION;
  digitalWrite(mFWD, HIGH); // STARTING WITH MOTOR OFF
  digitalWrite(mBWD, HIGH); // STARTING WITH MOTOR OFF
  Serial.begin(9600);       // SARTING THE SERIAL COMUNICATION ( IN THIS CASE, FOR THE BLUETOOTH ADAPTER );

  pinMode(mFWD, OUTPUT);
  pinMode(mBWD, OUTPUT);
  pinMode(flPin, OUTPUT);
  pinMode(blPin, OUTPUT);

} // END VOID SETUP

// PROTOTYPING FUNCTIONS
void FWD();
void BWD();
void LFT();
void RGT();
void FWDLFT();
void FWDRGT();
void BWDLFT();
void BWDRGT();
void fLIGHT();
void bLIGHT();
void STOP();

void loop()
{

  if (Serial.available())
  { // Serial.available(), VERIFY SERIAL PORT TO DISCOVERY IF IT'S ONLINE.

    byte command = Serial.read(); // Serial.read(), READS THE DATA ON BLUETOOTH PORT

    if (command == 'F')
    {

      FWD();
    }
    else if (command == 'B')
    {

      BWD();
    }
    else if (command == 'L')
    {

      LFT();
    }
    else if (command == 'R')
    {

      RGT();
    }
    else if (command == 'G')
    {

      FWDLFT();
    }
    else if (command == 'I')
    {

      FWDRGT();
    }
    else if (command == 'H')
    {

      BWDLFT();
    }
    else if (command == 'J')
    {

      BWDRGT();
    }
    else if (command == 'S')
    {

      STOP();
    }

    if (command == 'W')
    {

      digitalWrite(flPin, HIGH);
    }
    if (command == 'w')
    {

      digitalWrite(flPin, LOW);
    }
    if (command == 'U')
    {

      digitalWrite(blPin, HIGH);
    }
    if (command == 'u')
    {

      digitalWrite(blPin, LOW);
    }

  } // endIF Serial.Available()

} // EndVoidLoop

/*----------------------------
   CONTROL of DIRECTIONS
-----------------------------*/
void FWD()
{

  digitalWrite(mFWD, HIGH);
  digitalWrite(mBWD, LOW);

  Serial.println("FRENTE"); // FeedBack
}
void BWD()
{

  digitalWrite(mFWD, LOW);
  digitalWrite(mBWD, HIGH);
  Serial.println("TRAS"); // FeedBack
}
void LFT()
{

  servo.write(tLFT);
  Serial.println("ESQUERDA");
}
void RGT()
{

  servo.write(tRGT);
  Serial.println("DIREITA"); // FeedBack
}
void FWDLFT()
{

  servo.write(tLFT);
  digitalWrite(mFWD, LOW);
  Serial.println("FRENTE + ESQUERDA"); // FeedBack
}
void FWDRGT()
{

  servo.write(tRGT);
  digitalWrite(mFWD, LOW);
  Serial.println("FRENTE + DIREITA"); // FeedBack
}
void BWDLFT()
{

  servo.write(tLFT);
  digitalWrite(mBWD, LOW);
  Serial.println("TRAS + ESQUERDA"); // FeedBack
}
void BWDRGT()
{

  servo.write(tRGT);

  digitalWrite(mBWD, LOW);
  Serial.println("TRAS + DIREITA"); // FeedBack
}
void STOP()
{
  digitalWrite(mFWD, HIGH);
  digitalWrite(mBWD, HIGH);
  servo.write(ALGN);

  Serial.println("STOP"); // FeedBack
}

/*------------------------------------------------------
 #NOTE# THE LED CONFIGURATIONS IS INSIDE OF VOID LOOP.
--------------------------------------------------------
-------------------------------
    HEADLIGHT and LANTERN
-------------------------------

void fLIGHT(int status){

  digitalWrite(flPin,status);

}
void bLIGHT(int status){

  digitalWrite(blPin,status);
}
*/
