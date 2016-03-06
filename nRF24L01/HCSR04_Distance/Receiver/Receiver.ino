#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "pitches.h"

RF24 radio(7, 8);

long lastDistance = 0;

const byte rxAddr[6] = "00001";

const double tolerance = 0.20;

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();

  pinMode(3, OUTPUT);  
}

void loop()
{
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    
    long newDistance = 0;
    newDistance = atol(text);
    
    Serial.println(newDistance);       
    Serial.println(lastDistance);       
    if(lastDistance == 0){
      lastDistance = newDistance;
      Serial.println("Init");      
    }
    else if ((lastDistance*(1-tolerance)>newDistance)||(lastDistance*(1+tolerance)<newDistance))
    {
      Serial.println("Motion dection");
      // beep
      play();
    }
      lastDistance = newDistance;
  }
}

void play() {
  //tone(pin, note, duration)
    tone(3,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    tone(3,E4,Q); 
    delay(1+Q); 
    tone(3,E4,Q);
    delay(1+Q);
    tone(3,E4,Q);
    delay(1+Q);
    tone(3,F4,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,Ab4,E+S);
    delay(1+E+S);
    tone(3,G4,S);
    delay(1+S);
    
    tone(3,Gb4,S);
    delay(1+S);
    tone(3,E4,S);
    delay(1+S);
    tone(3,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(3,Bb3,E);
    delay(1+E);
    tone(3,Eb4,Q);
    delay(1+Q);
    tone(3,D4,E+S);
    delay(1+E+S);
    tone(3,Db4,S);
    delay(1+S);
    
    tone(3,C4,S);
    delay(1+S);
    tone(3,B3,S);
    delay(1+S);
    tone(3,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(3,F3,E);
    delay(1+E);
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    
    tone(3,C4,Q);
    delay(1+Q);
     tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,E4,H);
    delay(1+H);
    
     tone(3,LA4,Q);
    delay(1+Q);
    tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,Ab4,E+S);
    delay(1+E+S);
    tone(3,G4,S);
    delay(1+S);
    
    tone(3,Gb4,S);
    delay(1+S);
    tone(3,E4,S);
    delay(1+S);
    tone(3,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(3,Bb3,E);
    delay(1+E);
    tone(3,Eb4,Q);
    delay(1+Q);
    tone(3,D4,E+S);
    delay(1+E+S);
    tone(3,Db4,S);
    delay(1+S);
    
    tone(3,C4,S);
    delay(1+S);
    tone(3,B3,S);
    delay(1+S);
    tone(3,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(3,F3,E);
    delay(1+E);
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,LA3,Q);
    delay(1+Q);
     tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    delay(2*H);
    
}


