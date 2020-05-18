#include <stdio.h>
#include <stdlib.h>
 
//function to display bits of an unsigned int value 
void displayBits(unsigned int value);
//function to pack two characters values into an unsigned int variable 
void packCharacters(char c1, char c2);
 
int main()
{

  printf("PACKING CHARACTERS PROGRAM\n");
  printf("---------------------------\n");
   char char1, char2;
  //input for first character 
   puts("Enter first character: ");
   char1 = getchar();
   getchar();

  //input for second character
   puts("Enter second character: ");
   char2 = getchar();
   getchar();
   
  //print out results of binary conversion 
  printf("\n%c in binary: \n", char1);
  displayBits(char1);
  printf("\n%c in binary: \n", char2);
  displayBits(char2);
  printf("\n");

  packCharacters(char1, char2);

  return 0;
}

//function to display bits of an unsigned int value 
void displayBits(unsigned int value) {
  //define displayMask and left shift 31 bits 
  unsigned int displayMask = 1 << 31; 
  printf("%10u = ", value);

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

//function to pack two characters values into an unsigned int variable 
void packCharacters(char c1, char c2) {
  unsigned int ch;
  //assign char to c1, shift left 8 bits and then use inclusive OR for c2 
  ch = c1;
  ch = ch << 8;
  ch = ch | c2;

  //print packed results 
  printf("Packed: \n");
  displayBits(ch);
}
 
/*

Test Case 1: 

Enter first character: 
B 
Enter second character: 
D

B in binary: 
        66 = 00000000 00000000 00000000 01000010 


 in binary: 
        10 = 00000000 00000000 00000000 00001010 

Packed: 
     16906 = 00000000 00000000 01000010 00001010 

Test Case 2:

Enter first character: 
f
Enter second character: 
g

f in binary: 
       102 = 00000000 00000000 00000000 01100110 

g in binary: 
       103 = 00000000 00000000 00000000 01100111 

Packed: 
     26215 = 00000000 00000000 01100110 01100111 

Test Case 3: 

Enter first character: 
A
Enter second character: 
B

A in binary: 
        65 = 00000000 00000000 00000000 01000001 

B in binary: 
        66 = 00000000 00000000 00000000 01000010 

Packed: 
     16706 = 00000000 00000000 01000001 01000010 

*/
