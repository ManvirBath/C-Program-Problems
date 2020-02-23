#include <stdio.h>

int main(void) {

    int num = 15;  
    int spaces = num - 1;

    //loop for number of rows incremented
    for (int i = 0; i < num; i++) {  //loop for number of rows incremented
        //loop for spaces
        for (int j = 0; j < spaces; j++) { 
            printf(" ");
        }
        //first half of the stars
        for (int j = 0; j <= i; j++) {
            printf("* ");  
        }
        //newline to create loop for the bottom region 
        printf("\n");  
        //decrement spaces to go downward
        spaces--; 
    }
    spaces = 0;
    //loops for number of rows decremented for rows to align
    for (int i = num; i > 0; i--) {  
        //loops for spaces 
        for (int j = 0; j < spaces; j++) { 
            printf(" ");
        }
        //loop second half of stars
        for (int j = 0; j < i; j++) {  
            printf("* ");
        }
        printf("\n");
        //increment spaces so it goes upward
        spaces++; 
    }
}

/*

Sample Test 1: when num = 5
    *
   * *
  * * *
 * * * *
* * * * *
* * * * *
 * * * *
  * * *
   * *
    *

Sample Test 2: when num = 8
       *
      * *
     * * *
    * * * *
   * * * * *
  * * * * * *
 * * * * * * *
* * * * * * * *
* * * * * * * *
 * * * * * * *
  * * * * * *
   * * * * *
    * * * *
     * * *
      * *
       *

Sample Test 3: When num = 2
 *
* *
* *
 *

 Sample Test 4: When num = 15
               *
             * *
            * * *
           * * * *
          * * * * *
         * * * * * *
        * * * * * * *
       * * * * * * * *
      * * * * * * * * *
     * * * * * * * * * *
    * * * * * * * * * * *
   * * * * * * * * * * * *
  * * * * * * * * * * * * *
 * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
 * * * * * * * * * * * * * *
  * * * * * * * * * * * * *
   * * * * * * * * * * * *
    * * * * * * * * * * *
     * * * * * * * * * *
      * * * * * * * * *
       * * * * * * * *
        * * * * * * *
         * * * * * *
          * * * * *
           * * * *
            * * *
             * *
              *
*/
