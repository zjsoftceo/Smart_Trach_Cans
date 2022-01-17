/*================================================================================
  // Author : Zhang Jiang Open Source Technology
  // Project : Smart Trach Cans
  // Description : TowerPro Microservo_sg90 and HC-SR04 For Arduino NANO V3.0 Demo
  // Source-Code : Smart_Trach_Cans.ino
  // E-Mail :zjsoftceo@126.com
  //==============================================================================
*/
#include <Servo.h>
Servo TowerPro_SG90;
int TrigPin = 5;
int EchoPin = 6;
int TowerPro_SG90Pin = 7;
long duration , distance , average;
long aver[3];

void setup() {
  // put your setup code here, to run once:
  TowerPro_SG90.attach(TowerPro_SG90Pin);
  pinMode (TrigPin, OUTPUT);
  pinMode (EchoPin, INPUT);
  TowerPro_SG90.write(0);
  delay(500);
  TowerPro_SG90.detach();
}

void measdist()
{
  digitalWrite(10, HIGH);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(TrigPin, LOW);     // send waves for 10 us
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);

  pinMode (EchoPin, INPUT);
  duration = pulseIn(EchoPin, HIGH); // receive reflected waves
  distance = (duration / 2) / 10; // convert to distance
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 0; i <= 2; i++)
  {
    measdist();
    aver[i] = distance;
    delay(10);
  }
  
  distance = (aver[0] + aver[1] + aver[2]) / 3;

  if (distance < 50)
  {
    TowerPro_SG90.attach(TowerPro_SG90Pin);
    delay(2);
    TowerPro_SG90.write(0);
    delay(3000);
    TowerPro_SG90.write(150);
    delay(1000);
    TowerPro_SG90.detach();
  }

}
