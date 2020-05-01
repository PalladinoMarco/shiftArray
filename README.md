# shiftArray
C++ Template Functions to shift elements of an array to the left or right.

```C++
template <class A, size_t size> A shiftLeft(A (&array)[size]);
template <class A, size_t size> A shiftLeft(A (&array)[size], A newElement);
template <class A, size_t size> A shiftRight(A (&array)[size]);
template <class A, size_t size> A shiftRight(A (&array)[size], A newElement);
```

# Example in Serial Debug 
_Tested with AVR MCU; Arduino UNO (Atmega328P) and Leonardo (ATmega32u4)_

```C++
#include "shiftArray.h"

// char to dec table
#define L  76 // for char L
#define l 108
#define R  82 // for char R
#define r 114

static uint8_t ascii_check;

// command flag declaration
static bool shiftcmd;

// samples array definition
uint8_t samples[] = {1,2,3,4,5};

// dynamic samples quantity counter
byte samplesCount = sizeof(samples)/sizeof(samples[0]);

// serial receiver byte definition
uint8_t incomingByte = 0;

void setup() {
  // Serial initialize
  Serial.begin(9600);
  while(!Serial){}
  
  // set deafult shift side
  ascii_check = L;
  Serial.println("Shift Left. You can change shifting direction\ndigit 'R' for shifting right or 'L' for left.\nDigit value to shift");
  
  // print samples value
  for(uint8_t i=0; i < samplesCount; i++)
  {
    Serial.print(samples[i]);
    Serial.print(", ");
  }
  Serial.println();
}

void loop() {
  
  // command flag definition
  shiftcmd = false;
  
  // if serial byte receiver
  if (Serial.available())
  {
    // read the incoming byte:
    incomingByte = Serial.read();

    // check if command byte
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
        // shift and add new element
        *samples = shiftLeft<uint8_t>(samples, incomingByte);
        break;
  
        case R:
        // shift and add new element
        *samples = shiftRight<uint8_t>(samples, incomingByte);
        break;
      }
      
       // Print shifting samples values
       for(uint8_t i=0; i < samplesCount; i++)
        {
          Serial.print(samples[i]);
          Serial.print(", ");
        }
      Serial.println();
      }
    }
}
```
