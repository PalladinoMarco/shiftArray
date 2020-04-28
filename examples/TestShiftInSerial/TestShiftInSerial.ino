#include "shiftArray.h"

// char to dec table
#define L  76 // for char L
#define l 108
#define R  82 // for char R
#define r 114

static uint8_t ascii_check;
static bool shiftcmd;

// definizione vettore
uint8_t samples[] = {1,2,3,4,5};

byte samplesCount = sizeof(samples)/sizeof(samples[0]);
uint8_t incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  ascii_check = L;
  Serial.println("Shift Left. You can change shifting direction\ndigit 'R' for shifting right or 'L' for left.\nDigit value to shift");
  for(uint8_t i=0; i < samplesCount; i++)
  {
    Serial.print(samples[i]);
    Serial.print(", ");
  }
  Serial.println();
}

void loop() {
  
  shiftcmd = false;
  
  if (Serial.available())
  {
    // read the incoming byte:
    incomingByte = Serial.read();

    if(incomingByte == R || incomingByte == r)
    {
      ascii_check = R;
      shiftcmd = true;
    }
    else if(incomingByte == L || incomingByte == l)
    {
      ascii_check = L;
      shiftcmd = true;
    }
    
    incomingByte -= '0';

    if(!shiftcmd)
    {
      switch(ascii_check)
      {
        case L:
        *samples = shiftLeft<uint8_t>(samples, incomingByte);
        break;
  
        case R:
        *samples = shiftRight<uint8_t>(samples, incomingByte);
        break;
      }
      
       // Print values
       for(uint8_t i=0; i < samplesCount; i++)
        {
          Serial.print(samples[i]);
          Serial.print(", ");
        }
      Serial.println();
      }
    }
}
