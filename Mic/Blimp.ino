//Fin the Electret Blimp is the original creation of
//Pritika Nilaratna
//Ollie is Licensed under the Attribution-ShareAlike 3.0 Unported License
//Please share your projects under the same license!
//Code Developed from Sparkfun SIK
//Hardware and Design adopted from Ollie


#include <Servo.h> // Servo Library
Servo servoL; //Left Servo Control Object
Servo servoR; //Right Servo control Object

//Sound variables
const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int sound;


void setup()
{
  servoL.attach(5);  // attaches the left servo on pin 5
  servoR.attach(6);  // attached the right servo on pin 6
  Serial.begin(9600); // open the serial port at 9600 bps:
 }


void loop()
{
  int position=0;
  servoL.write(0); //Set the position of Left fin
  servoR.write(0); //set the position of Right fin

  //set up sound detection
  unsigned long start= millis();  // Start of sample window
  unsigned int peakToPeak = 0;    // peak-to-peak level
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 250 miliseconds
  while (millis() - start < sampleWindow)
   {
     sound = analogRead(0);
       if (sound < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
         {
           if (sound > signalMax)
            {
              signalMax = sound;  // save just the max levels
            }
           else if (sound < signalMin)
            {
               signalMin = sound;  // save just the min levels
            }
         }
   }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
  Serial.print("Volts:");
  Serial.print("\t");
  Serial.println(volts);
  if (volts >=1.0)
   {

    //To make your Blimp seem more excited copy and paste
    // the "Up Motion" and "Down Motions" as many
    //Time as you'd like. Right now his fins will flap
    //4 times.

     Serial.println("HEY!! HELLO!!"); //Should have named it NAVI
     for (position =0; position <= 75; position +=5)//Up Motion
        {
        servoL.write(position); //move Left Fin to next position
        servoR.write(position); //move Right Fin to next position
        delay(20);
        }
      for (position = 75; position>=0; position -=5)//Down Motion
        {
         servoL.write(position); //move Left Fin to Next position
         servoR.write(position); // move Right Fin to Next position
         delay(20);
        }
      for (position =0; position <= 75; position +=5)//Up motion
        {
        servoL.write(position); //move Left Fin to next position
        servoR.write(position); //move Right Fin to next position
        delay(20);
        }
      for (position = 75; position>=0; position -=5) // Down Motion
        {
         servoL.write(position); //move Left Fin to Next position
         servoR.write(position); // move Right Fin to Next position
         delay(20);
        }
        delay(800); // This delay helps the elecret mic recover from hearing
        //the sound of the Servo motors.
    }
}

//end. Change it up and show us if you've made one and how you modified it!
