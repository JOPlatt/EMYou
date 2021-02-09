const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int sample;
int Wind = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(Wind, OUTPUT);
}

void loop()
{
unsigned long startMillis= millis();  // Start of sample window
unsigned int peakToPeak = 0;   // peak-to-peak level

unsigned int signalMax = 0;
unsigned int signalMin = 1024;

// collect data for 1 second
while (millis() - startMillis < sampleWindow)
{
      sample = analogRead(0);
    if (sample < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
    {
         if (sample > signalMax)
        {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
 double volts = (peakToPeak * 3.3) / 1024;  // convert to volts


Serial.println(volts);
if (volts >=0.5)
{
    //turn on FAN
    digitalWrite(Wind, HIGH);
delay(1000);
  digitalWrite(Wind, LOW);
delay(75);
  digitalWrite(Wind, HIGH);
delay(75);
  digitalWrite(Wind, LOW);
delay(75);
  digitalWrite(Wind, HIGH);
delay(75);
  digitalWrite(Wind, LOW);
delay(75);
  digitalWrite(Wind, HIGH);
delay(75);
   }
  else
  {
  //turn FAN off
 digitalWrite(Wind, LOW);
 }
}
