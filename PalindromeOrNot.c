#include <stdio.h>

int main(void) {

    int n;  //integer variables used 
    int reverse = 0;

    //headline of program
    printf("Palindrome or not?");  
    printf("\n--------------------");

    //scanner for accepting input
    printf("\nEnter a five-digit integer: "); 
    scanf_s("%d", &n);

    int tempN = n;
    //check if integer is between 10000-99999 before moving forward 
    if (tempN < 10000 || tempN > 99999) {  
        printf("That's not a five-digit integer!");
        return 0;
    }

    while (tempN > 0) { 
        //muliply in order to move from right to left - ones column to tens to hundreds, etc
        reverse *= 10;  
        // adds numbers together and eliminates previous one til the end
        reverse += tempN % 10;   
        //loops backward from left to right 
        tempN /= 10; 
    }
    //if number ends up equaling reverse, return first statement
    if (n == reverse) {  
        printf("%d is a palindrome", n);
    }
    else {
        printf("%d is not a palindrome", n);
    }
}

/*
Sample Test 1:
Palindrome or not?
--------------------
Enter a five-digit integer: 11011
11011 is a palindrome

Sample Test 2:
Palindrome or not?
--------------------
Enter a five-digit integer: 95231
95231 is not a palindrome

Sample Test 3:
Palindrome or not?
--------------------
Enter a five-digit integer: 59395
59395 is a palindrome

Sample Test 4: 
Palindrome or not?
--------------------
Enter a five-digit integer: 906609
That's not a five-digit integer!
*/