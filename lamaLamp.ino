int led = 9;           // the pin that the LED is attached to
int led2 = 6;
int brightness = 0;    // how bright the LED is
int fadeAmount = 10;    // how many points to fade the LED by
int limit = 255;
int input = 0;

void setup()  { 
  
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
} 

void loop()  { 
  
    input = Serial.read();
    
    //Serial.print("input: ");
    //Serial.println(input);
    
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
    
    case '9':
      brightness = 10;
      Serial.print("Nachtlicht (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    
    case '+':
      brightness = brightness + fadeAmount;
      if (brightness >= limit) {
        brightness = limit;
      }
      Serial.print("heller (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    
    case '-':
      brightness = brightness - fadeAmount;
      if (brightness <= 0) {
        brightness = 0;
      }    
      Serial.print("dunkler (");
      Serial.print(brightness);
      Serial.println(")");
    break;
    }
       
  analogWrite(led, brightness);
  analogWrite(led2, brightness);  
  }
/*
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness >= 200) {
    fadeAmount = -fadeAmount; 
  } 
if (brightness <= 0) {
fadeAmount = -fadeAmount; 
}
*/
