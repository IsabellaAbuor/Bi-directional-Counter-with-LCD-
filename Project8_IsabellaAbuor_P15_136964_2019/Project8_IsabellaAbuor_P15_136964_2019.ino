#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define sensorPin1 7
#define sensorPin2 8

int sensorState1 = 0;
int sensorState2 = 0;
int count=0;

void setup()
{
  pinMode (sensorPin1,INPUT);
  pinMode (sensorPin2, INPUT);
  
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("COUNTER");
  lcd.setCursor(0,1);
  lcd.print("No Visitors     ");
  delay(200);
}

void loop()
{  
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);

  if(sensorState1 == LOW){
    count++; 
    delay(500);
  }

  if(sensorState2 == LOW){
    count--; 
    delay(500);
  }
  

   if(count<=0)
  {
    lcd.setCursor(0,1);
    lcd.print("No visitors    ");
  }
  else if (count>0 && count<10){
    lcd.setCursor(0,1);
    lcd.print("Visitors:   ");
    lcd.setCursor(12,1);
    lcd.print(count);
    lcd.setCursor(13,1);
    lcd.print("  "); 
    
  }
  else {
    lcd.setCursor(0,1);
    lcd.print("Visitors:   ");
    lcd.setCursor(12,1);
    lcd.print(count);  
  }
}
