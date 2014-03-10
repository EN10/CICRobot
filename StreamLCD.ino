#include <LiquidCrystal.h>
char ip[14];
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char LastByte;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
 while(Serial.available() > 0){
  SerialRead();
  }
}

void SerialRead(){
  if (Serial.available() > 0)
  { 
    lcd.clear();
    LastByte = Serial.readBytesUntil(13,ip,14); //Read 35 Bytes from the buffer or untill ASCII Char 13 found. Store in array "data" 
    ip[LastByte] = 0; // add a 0 terminator 
      lcd.print("IP: ");
      lcd.print(ip);
    Serial.println(ip);
    delay(100);
  }
}

