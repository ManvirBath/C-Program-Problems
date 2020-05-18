#include <stdio.h>
#include <stdlib.h>

//function to display bits of an unsigned int value 
void displayBits(unsigned int value);
//function to unpack two characters from unsigend int variable 
void unpackCharacters(unsigned int integer);

int main(void) {
  unsigned int number; 

  printf("UNPACKING CHARACTERS PROGRAM\n");
  printf("----------------------------\n");
  //reader 
  puts("Enter non-negative number: ");
  scanf("%u", &number);

  //print results in binary then unpack 
  printf("\n%u in binary: \n", number); 
  displayBits(number);

  printf("\n");
  unpackCharacters(number);

  return 0;
}

void displayBits(unsigned int value) {
  //define displayMask and left shift 31 bits 
  unsigned int displayMask = 1 << 31; 
  printf("%u = ", value);

  //loop through bits 
  for(unsigned int c = 1; c <= 32; ++c) {
    putchar(value & displayMask ? '1' : '0');
    //shift value left by 1
    value <<= 1;

    //output space after 8 bits 
    if(c % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}

//function to unpack two characters from unsigend int variable 
void unpackCharacters(unsigned int integer) {
  unsigned int mask1 = 65280, mask2 = 255;
  //combining by using AND operation 
  unsigned int combine = integer & mask1;
  //right shift result by 8 bits 
  char c1 = (char) (combine >> 8);
  //combining by using AND operation 
  char c2 = (char) integer & mask2;

  //print result for first character 
  printf("First unpacked character: %c", c1);
  printf("\n");
  displayBits(c1);

  //print result for second character 
  printf("Second unpacked character: %c", c2);
  printf("\n");
  displayBits(c2);
}

/* 

Test Case 1: 

Enter non-negative number: 
17477

17477 in binary: 
17477 = 00000000 00000000 01000100 01000101 

First unpacked character: D
68 = 00000000 00000000 00000000 01000100 
Second unpacked character: E
69 = 00000000 00000000 00000000 01000101 

Test Case 2:

Enter non-negative number: 
25187

25187 in binary: 
25187 = 00000000 00000000 01100010 01100011 

First unpacked character: b
98 = 00000000 00000000 00000000 01100010 
Second unpacked character: c
99 = 00000000 00000000 00000000 01100011 

Test Case 3: 

Enter non-negative number: 
19802

19802 in binary: 
19802 = 00000000 00000000 01001101 01011010 

First unpacked character: M
77 = 00000000 00000000 00000000 01001101 
Second unpacked character: Z
90 = 00000000 00000000 00000000 01011010 

*/