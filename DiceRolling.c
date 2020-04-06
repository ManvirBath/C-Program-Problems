#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoll(int die1, int die2, int tally[]);

int main(void) {
    //generates numbers at random
    srand(time(NULL));

    //declare variables for both die and array of tally
    int x = 0;
    int y = 0;
    int z[13] = { 0 };
    int sum = diceRoll(x, y, z);

    //iterate through 2 and 12, adds tally of numbers of possible sums 
    //prints it table format 
    for (int i = 2; i <= 12; i++) {
        printf("%3d%12d\n", i, z[i]);
        sum += z[i];
    }
    printf("\n The total number of rolls is %d", sum);
}

//this function iterates each die 1 to 36000 times and tally adds up the dies
//then increments pointer for tally 
int diceRoll(int die1, int die2, int tally[]) {

    for (int i = 1; i <= 36000; i++) {
        die1 = 1 + rand() % 6;
        die2 = 1 + rand() % 6;
        tally[die1 + die2]++;
    }
    return 0;
}
/* 
Test case 1: 
  2        1089
  3        1959
  4        2897
  5        3993
  6        5047
  7        6071
  8        4986
  9        4001
 10        3021
 11        1970
 12         966

 The total number of rolls is 36000

 Test case 2: 
  2        1005
  3        2063
  4        2988
  5        3905
  6        4980
  7        6084
  8        4922
  9        4005
 10        3021
 11        1998
 12        1029

 Test case 3: 
  2        969
  3        1967
  4        3058
  5        3992
  6        4961
  7        5997
  8        4987
  9        4037
 10        3040
 11        1980
 12        1012
*/