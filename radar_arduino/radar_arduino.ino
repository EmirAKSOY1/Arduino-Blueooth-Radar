// Robimek - Android radar projesi
#include <NewPing.h>
#include <Servo.h>
 
#define Servo_pin 11
#define trigPin 9
#define echoPin 8
#define Maks_mesafe 200
#define ACI_SINIRI 80 // açı değeri -80 ile 80 derece arasındadır.
#define ACI_KATSAYISI 1 // servonun hareketinde uygulanan artış katsayısı

long duration;
int distance;

Servo Servo_motor;
 
//NewPing ultrasonik(Trig_pin, Echo_pin, Maks_mesafe);
 
int ACI_DEGERI = 0;
int Mesafe = 0;
int dir = 1;
 
void setup()
{
Servo_motor.attach(Servo_pin);
Serial.begin(19200);
pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
 
void loop()
{/*
delay(10);
 
Servo_motor.write(ACI_DEGERI + ACI_SINIRI);
 
//Mesafe = ultrasonik.ping_cm(); // mesafeyi cm cinsinden ölç
  distance = calDist();
Serial.print(ACI_DEGERI);
Serial.print(",");
Serial.print(distance,DEC);
Serial.print(".");


// Açı Değişkeni açı sınırlarının birine ulaşmışsa, yön değiştir
if (ACI_DEGERI >= ACI_SINIRI || ACI_DEGERI <= -ACI_SINIRI)
{
dir = -dir;
}
 
ACI_DEGERI += (dir * ACI_KATSAYISI); // yeni açı değeri*/

for(int i=15;i<=165;i++){            // rotates the servo motor from 15 to 165 degrees
    Servo_motor.write(i);
    delay(30);
    distance = calDist();

    Serial.print(i);                      // Sends the current degree into the Serial Port
    Serial.print(",");                   // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);                // Sends the distance value into the Serial Port
    Serial.print(".");                   // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
      }

    for(int i=165;i>15;i--){  
    Servo_motor.write(i);
    delay(30);
    distance = calDist();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    }


}
int calDist()
{
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
                                                                // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
                                                              // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
                                                              // Calculating the distance
  distance= duration*0.034/2;                                // Range : 2cm to 400 cm

  return distance;
}
