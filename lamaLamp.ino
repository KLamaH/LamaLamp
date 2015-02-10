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
int sensorValue = 0;
String state = "off";

void setup()  { 
  
  Serial.begin(9600);  //begin serial communication
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
} 

void loop()  { 
  
    input = Serial.read();
    sensorValue = analogRead(A0);

    switch (input) {    
    case '0':
      brightness = 0;
      state = "OFF";
      printState();
    break; 
    case '1':
      brightness = 64;
      state = "ON";
      printState();
    break;
    case '2':
      brightness = 127;
      state = "ON";
      printState();
    break; 
    case '3':
      brightness = 192;
      state = "ON";
      printState();
    break;
    case '4':
      brightness = 255;
      state = "ON";
      printState();
    break;
    case '8':
      if (fade == false) {
        fade = true;
        state = "FADING";
        printState();
      }
      else {
        fade = false;
        state = "ON";
        printState();
      }
    break;
    case '9':
      brightness = 10;
      state = "NIGHTLIGHT";
      printState();;
    break;
    case '+':
      state = "ON";
      dimUp();
      printState();
    break;
    case '-':
      state = "ON";
      dimDown();    
      printState();;
    break;
    }
    
  delay(fadeDelay);
  
  analogWrite(led, brightness);
  analogWrite(led2, brightness);
  
  //Serial.println(sensorValue);


  if (fade == true) {    
    fader();
  }
}
  
  //---------------------------------------------------------------------//
  
  void fader () {
         if (fadeDir == true) {
      if ((brightness + fadeAmount) >= limit) {
       brightness = limit;
       fadeDir = false; 
      }
      else {
        fadeUp();
      }
    }
      else { 
      if ((brightness - fadeAmount) <= 0) {
        brightness = 0;  
        fadeDir = true;
      }
       else {
         fadeDown();
       }
      }
  }
  
  void dimUp() {
    brightness = brightness + dimAmount;
    if (brightness >= limit) {
        brightness = limit;
    }
  }
  
  void dimDown() {
    brightness = brightness - dimAmount;
    if (brightness <= 0) {
        brightness = 0;
        state = "OFF";
    }
  }
  
  void fadeUp() {
    brightness = brightness + fadeAmount;
    if (brightness >= limit) {
        brightness = limit;
    }
   }
  
  void fadeDown() {
    brightness = brightness -fadeAmount;
    if (brightness <= 0) {
        brightness = 0;
     }
    }
  
  void printState() {
    Serial.print(state);
    Serial.print(" ");
    Serial.print("Brightness: ");
    Serial.println(brightness);
  }
  


