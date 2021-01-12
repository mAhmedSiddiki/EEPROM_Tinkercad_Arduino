#include<EEPROM.h>

int zz;
int EEsize = 1024;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{
  Serial.println("Writing random numbers: ");
  for(int i=0; i<EEsize; i++){
  	zz=random(255);
    EEPROM.write(i,zz);
  }
  
  Serial.println();
  
  for(int j=0; j<EEsize; j++){
  	zz=EEPROM.read(j);
    Serial.print("EEPROM position: ");
    Serial.print(j);
    Serial.print("Contains ");
    Serial.println(zz);
    delay(25);
  }
}