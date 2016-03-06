#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* Utilisation du capteur Ultrason HC-SR04 */
// définition des broches utilisées 
int trig = 4; 
int echo = 3; 
long lecture_echo; 
long cm =0;



RF24 radio(7, 8);

const byte rxAddr[6] = "00001";

void setup()
{
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();

// Utilisation du capteur Ultrason HC-SR04 
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 

}

void loop()
{
/* Utilisation du capteur Ultrason HC-SR04 */
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; 

  char text[] = "Hello World";
  sprintf(text,"%ld",cm);
  Serial.print("Distancem : "); 
  Serial.println(text);  
   
  
  radio.write(&text, sizeof(text));
  
  delay(250);
}
