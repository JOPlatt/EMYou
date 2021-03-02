const int pin_sp = A1;    // Pin connected to SoftPot
const int pin_red = 3;    // Pin connectced to red button
const int pin_blue = 4;   // Pin connected to blue button
const int led_red = 6;    // Pin connected to red LED
const int led_green = 7;  // Pin connected to green LED
const int led_blue = 8;   // Pin connected to blue LED

bool pushed_red = false;  // Initialise red button state
bool pushed_blue = false; // Initialise blue button state

void setup() {
  Serial.begin(9600);
  pinMode(pin_sp, INPUT);
  pinMode(pin_red, INPUT_PULLUP);
  pinMode(pin_blue, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
}

void loop() {
  bool prev_red = pushed_red;    //Initialise variable for red button
  bool prev_blue = pushed_blue; // Initialise variable for blue button

  pushed_red = digitalRead(pin_red) == LOW;   // Initialise red button ON
  pushed_blue = digitalRead(pin_blue) == LOW; // Initalise blue button ON

//  if(digitalRead(pin_sp) == LOW)  // Read SoftPot, if SoftPot has NO pressure, turn OFF all LED colours
//  {
//    digitalWrite(led_red, LOW);
//    digitalWrite(led_green, LOW);
//    digitalWrite(led_blue, LOW);
//  }
//  else                            // If SoftPot has pressure, turn ON green LED ONLY
//  {
//    digitalWrite(led_red, LOW);
//    digitalWrite(led_green, HIGH);
//    digitalWrite(led_blue, LOW);
//  }

  if (prev_red != pushed_red)        // If red button is OFF, turn OFF all LED colours
  {
    if (pushed_red)
    {
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
    }
    else                            // If red button is ON, turn ON red LED ONLY
    {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
    }
  }

    if (prev_blue != pushed_blue)   // If blue button is OFF, turn OFF all LED colours
  {
    if (pushed_blue)
    {
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
    }
    else                            // If blue button is ON, turn ON blue LED ONLY
    {
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, HIGH);
    }
  }
}
