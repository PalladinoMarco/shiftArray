# shiftVector
shift elements in the Vector 1D

# Example in Serial Debug (Tested with Arduino on AVR Atmega328P)

```C++
#include "shiftVector.h"
//using namespace shift;

// char to dec table
#define L  76 // for char L
#define l 108
#define R  82 // for char R
#define r 114

static uint8_t ascii_check;
static bool shiftcmd;

// definizione vettore
unsigned int short sample[] = {1,2,3,4,5};

byte sampleCount = sizeof(sample)/sizeof(sample[0]);
int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  ascii_check = L;
  Serial.println("Shift Left. You can change shifting direction\ndigit 'R' for shifting right or 'L' for left.\nDigit value to shift");
  for(unsigned int short i=0; i < sampleCount; i++)
  {
    Serial.print(sample[i]);
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
        *sample = shiftLeftVector<unsigned int short>(sample, incomingByte);
        break;
  
        case R:
        *sample = shiftRightVector<unsigned int short>(sample, incomingByte);
        break;
      }
      
       // Print values
       for(unsigned int short i=0; i < sampleCount; i++)
        {
          Serial.print(sample[i]);
          Serial.print(", ");
        }
      Serial.println();
      }
    }
}

```
