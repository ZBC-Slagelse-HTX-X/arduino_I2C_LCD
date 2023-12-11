#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);



int trig = 2;
int echo = 3;
long   duretion, distance;


void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2,0);
   lcd.print("Distance");

  lcd.setCursor(1,1);
  lcd.print("UltraSonic");
   delay(2000);
  
  lcd.clear();
}

void loop() {
  digitalWrite(trig,HIGH);
   delayMicroseconds(2);
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
   digitalWrite(trig,HIGH);

  duretion = pulseIn(echo,HIGH);
  distance   = (duretion/2)*0.0346;

  lcd.setCursor(3,0);
  lcd.print(distance);

  lcd.setCursor(6,0);
  lcd.print("cm");
  
}
