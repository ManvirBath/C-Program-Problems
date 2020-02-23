#include <stdio.h>
#include <math.h>

int main(void) {

    long long n;   //int variables used 
    int count = 0;
    int remainder;
    int sum = 0;

    printf("Binary to decial number converter\n");    //headline of program 
    printf("-----------------------------------");

    printf("\nEnter binary number: ");  // scanner to accept input
    scanf_s("%lld", &n);

    //continue to loop as long as number greater than 0
    while (n > 0) {
        //start from the least significant bit 
        remainder = n % 10;
        n /= 10;    //moves to the next least significant bit 
        sum += remainder * pow(2, count);  //calculates sum of the numbers from right to left
        ++count;  //increment the count for the power of 2 every time 
    }
    printf("Conversion to decimal number is %d", sum);  //print result 
}

/*

Sample Test 1:
Binary to decial number converter
-----------------------------------
Enter binary number: 11111
Conversion to decimal number is 31

Sample Test 2:
Binary to decial number converter
-----------------------------------
Enter binary number: 00111
Conversion to decimal number is 7

Sample Test 3:
Binary to decial number converter
-----------------------------------
Enter binary number: 10101111
Conversion to decimal number is 175

Sample Test 4: 
Binary to decial number converter
-----------------------------------
Enter binary number: 01111111111011011
Conversion to decimal number is 65499

*/