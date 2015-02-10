int led = 9;           //pin for controlling the first bunch of LEDs
int led2 = 6;          //pin for controlling the second bunch of LEDs
int brightness = 0;    //how bright the LEDs are when the lamp is pluged in
int dimAmount = 10;
int fadeAmount = 1;   //how many points in the PWM-range to dim the LED
int fadeDelay = 10;    //the bigger the delay, the slower it fades
boolean fadeDir = true;//if fadeDir is true it fades up, if it is false it fades down
int limit = 255;       //limit the brightness (PWM-range is from 0=off to 255=bright)
int input = 0;
boolean fade = false;

void setup()  { 
  
  Serial.begin(9600);  //begin serial communication
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
} 

void loop()  { 
  
    input = Serial.read();
    
    switch (input) {    
    case '0':
      brightness = 0;
      Serial.print("Helligkeit: 0% (");
      Serial.print(brightness);
      Serial.println(")");
    break; 
    case '1':
      brightness = 64;
      Serial.print("Helligkeit: 25% (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    case '2':
      brightness = 127;
      Serial.print("Helligkeit: 50% (");
      Serial.print(brightness);
      Serial.println(")");
    break; 
    case '3':
      brightness = 192;
      Serial.print("Helligkeit: 75% (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    case '4':
      brightness = 255;
      Serial.print("Helligkeit: 100% (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    case '8':
      if (fade == false) {
        fade = true;
        Serial.println("fade = on");
      }
      else {
        fade = false;
        Serial.println("fade = off");
      }
    break;
    case '9':
      brightness = 10;
      Serial.print("Nachtlicht (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    case '+':
      brightness = brightness + dimAmount;
      if (brightness >= limit) {
        brightness = limit;
      }
      Serial.print("heller (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    case '-':
      brightness = brightness - dimAmount;
      if (brightness <= 0) {
        brightness = 0;
      }    
      Serial.print("dunkler (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    }
    
  delay(fadeDelay);
  
  analogWrite(led, brightness);
  analogWrite(led2, brightness);


  if (fade == true) 
  {    
    if (fadeDir == true)
    {
      if ((brightness + fadeAmount) >= limit) 
      {
       brightness = limit;
       fadeDir = false; 
      }
      else
      {
        brightness = brightness + fadeAmount;
      }
    }
      else
    { 
      if ((brightness - fadeAmount) <= 0)
      {
        brightness = 0;  
        fadeDir = true;
      }
       else
       {
         brightness = brightness - fadeAmount;
       }
    } 
  }
}

