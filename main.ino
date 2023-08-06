#define sober 29
#define Drunk 30

#define MQ3 0
#include <LiquidCrystal.h>

const int rs = 7, en = 9 , d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int motorPin = A1;     // the pin that the motor is attached to
int motorSpeed = A2;   // variable to store the speed of the motor
int led = 8;
int buzzer = 5;
float sensorValue = 0;


void setup() {
  
  lcd.begin(16, 2);
  lcd.print("Engine turned On");
  pinMode(motorPin, OUTPUT);
   pinMode(motorSpeed, OUTPUT);
   pinMode(led , OUTPUT);



  Serial.begin(9600);
  Serial.println("Engine has turned on!!");
  delay(2000);
}

void loop() {
  // Ramp up the motor speed from 0 to 255
   sensorValue = analogRead(MQ3);
  // Ramp down the motor speed from 255 to 0
  // delay(1000);
  // sensorValue = analogRead(MQ3);
  // Serial.print("Sensor value: ");
  // Serial.print(sensorValue);

  if(sensorValue  < 25){
    
    motorSpeed = 255;
    // brightness = i;
    analogWrite(motorPin, motorSpeed);
    digitalWrite(led , LOW);
    // analogWrite(led, brightness);
    Serial.print("Sensor value: ");
     Serial.print(sensorValue);
    Serial.print(" - Motor Speed: ");
    Serial.print(motorSpeed);
    Serial.println(" Status: Sober");
    lcd.begin(16, 2);
    lcd.print("  State: Sober  ");
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  String output = "speed: : " + String(motorSpeed);
  lcd.print(output);
    delay(500);

  }
  else if(sensorValue > 35 && sensorValue < 100){
    
    
    motorSpeed = 130;
    // brightness = i;
    analogWrite(motorPin, motorSpeed);
    digitalWrite(led , LOW);
    // analogWrite(led, brightness);
    Serial.print("Sensor value: ");
     Serial.print(sensorValue);
    Serial.print(" - Motor Speed: ");
    Serial.print(motorSpeed);
    Serial.println(" Status: drinking but within limits");
    lcd.begin(16, 2);
    lcd.print("within the limit");
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  String output = "speed: : " + String(motorSpeed);
  lcd.print(output);
    delay(500);

  }
  else if(sensorValue > 100){
    
    Serial.print("Sensor value: ");
     Serial.print(sensorValue);
    Serial.println(" Status: Drunk");
    Serial.println(" Engine has turned off!!");
    lcd.print("Engine Off");
    digitalWrite(led , HIGH);
    digitalWrite(buzzer , HIGH);

    motorSpeed = 0;

    analogWrite(motorPin, motorSpeed);
     lcd.begin(16, 2);
    lcd.print(" Status: Drunk  ");
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
    lcd.print("   Engine Off   ");
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
    // lcd.print(millis() / 1000);
    
    delay(2000000);


}


}
