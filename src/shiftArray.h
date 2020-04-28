#pragma once

/***********************************************************************************************************************************
  @file shiftArray
  @author Marco Palladino <marck.palladino@gmail.com>
  @version 1.0 @date 2020/04/12

  @details
  Shift elements of an array to the left or right.

  # LICENSE #
  
  MIT License
  
  Copyright (c) 2020 Marco Palladino
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROAIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EAENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 
***********************************************************************************************************************************/

// shift left
template <class A, size_t size> A shiftLeft(A (&array)[size])
{ 
  // byte size to avoid memmove overflows
  byte byteCut = sizeof(array[0]);
  
  for(size_t i = 0; i < size; i++)
  {
    memmove(&array[i], &array[i+1], byteCut);
  }
  return *array;
}

// shift left and add a value at the end.
template <class A, size_t size> A shiftLeft(A (&array)[size], A newElement)
{
  *array = shiftLeft<A>(array);
  array[size-1] = newElement;
  return *array;
}

// shift Right
template <class A, size_t size> A shiftRight(A (&array)[size])
{ 
  byte byteCut = sizeof(array[0]);
  
  for(size_t i = size; i > 0; i--)
  {
    memmove(&array[i], &array[i-1], byteCut);
  }
  return *array;
}

// shift Right and add a value at the end.
template <class A, size_t size> A shiftRight(A (&array)[size], A newElement)
{
  *array = shiftRight<A>(array);
  array[0] = newElement;
  return *array;
}
