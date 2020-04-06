#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

/*
function for strcpy, strncpy, strcat, strncat. the first and second string are used to make the comparisons for array subscripting and pointers/pointer arithmetic.
strcpy and strncpy are string functions used to copy the strings whereas the strcat and strncat are string functions used to concatentate the strings
*/ 

//x and y represent the strings, and size_t num is utilized as a count 
char *string_copy(char *x, char *y);
char *string_copy2(char *x, char *y);
char *strn_copy(char *x, char *y, size_t num);
char *strn_copy2(char *x, char *y, size_t num);
char *str_cat(char *x, char *y);
char *str_cat2(char *x, char *y);
char *strn_cat(char *x, char *y, size_t num);
char *strn_cat2(char *x, char *y, size_t num);

int main(void) {
  //first step is to handle the initialization 
  int num = 3;
  //string 1 and string 2 test values 
  char str1[50];
  char str2[50];

  //reader input 
  printf("Input string: ");
  scanf("%s",str2);
  printf("\n");

  //results for strcpy and strncpy 
  printf("string_copy returned %s\n", string_copy(str1, str2));
  printf("string_copy2 returned %s\n", string_copy2(str1, str2));

  printf("%d number of elements returned from strn_copy %s\n", num, strn_copy(str1, str2, num));
  printf("%d number of elements returned from strn_copy2 %s\n", num, strn_copy2(str1, str2, num));

  //results for strcat and strncat 
  printf("str_cat returned %s\n", str_cat(str1, str2));
  printf("str_cat2 returned %s\n", str_cat2(str1, str2));

  printf("%d number of concatenated elements returned strn_cat %s\n", num, strn_cat(str1, str2, num));
  printf("%d number of concatenated elements returned strn_cat2 %s\n", num, strn_cat2(str1, str2, num));

  return 0;
}
//representation of pointers: (a, b), representation of strings(x, y) and size_t num as a count

//using array subscripting for strcpy
char *string_copy(char *x, char *y) {
  int i; 
  char *z = x;
  //second array copied into the first 
  for(i = 0; (y[i] != '\0'); i++) {
    x[i] = y[i]; 
  }
  //finish with null element and returns a value 
  x[i] = '\0';
  return x;
}

//using pointer arithmetic for strcpy
char *string_copy2(char *x, char *y) {
  //these pointers are going to be used to point a to x and y to b 
  char *a, *b; 
  //second elements copied into first 
  for(a = x, b = y; *b != '\0'; a++, b++) {
    *a = *b;
  }
  //finish with null element and returns a value 
  *a = '\0';
  return x; 
}

//using array subscripting for strncpy 
char *strn_copy(char *x, char *y, size_t num) {
  //z points to x 
//  char *z = x;
  size_t j;

  //copy each element of y 
  for(j = 0; j < num; j++) {
    x[j] = y[j];
  }
  //finish with null element and returns z value 
  x[j] = '\0';
  return x; 
}

//using pointer arithmetic for strncpy
char *strn_copy2(char *x, char *y, size_t num) {
  //a points to x, b points to y 
  size_t j;
  char *a = x;
  char *b = y;
  //copy each elment of y
  for(j = 0; j < num; a++, b++, j++) {
    *a = *b; 
  }
  //finish with null element and returns a value 
  *a = '\0';
  return x;
}

//using array subscripting for strcat 
char *str_cat(char *x, char *y) {
  int i, j;
  //when it comes to concatenating, two loops are required for the first being to find the chars which are null and the second for copying elements of second array into first 
  for(i = 0; x[i] != '\0'; i++) {
    //leave it as empty statement 
    ;
  }
    for(j = 0; y[j] != '\0'; i++, j++) {
      x[i] = y[j];
    }
  //finish with null element and returns a value
  x[i] = '\0';
  return x;
}

//using pointer arithmetic for strcat
char *str_cat2(char *x, char *y) {
  int i;
  //a points to x, b points to y 
  char *a, *b;
  //when it comes to concatenating, two loops are required for the first being to find the chars which are null and the second for copying elements of second array into first 
  for(a = x; *a != '\0'; a++) {
    //leave it as empty statement 
    ; 
  }
    for(b = y; *b != '\0'; a++, b++) {
      *a = *b;
    }
  //finish with null element and returns a value
  *a = '\0';
  return x;
}

//using array subscripting for strncat 
char *strn_cat(char *x, char *y, size_t num) {
  size_t j, k;
  //handles if elements for the string array of x is copied into y causing incrementation 
  for(j = 0; x[j] != '\0'; j++) {
    //leave it as empty statement
    ;
  }
    for(k = 0; k < num; j++, k++) {
      x[j] = y[k];
    }
  //finish with null element and returns a value
  x[j] = '\0';
  return x;
}

//using pointer arithmetic for strncat
char *strn_cat2(char *x, char *y, size_t num) {
  size_t i;
  char *a = x;
  char *b = y;
  //handles if elements for the string array of x is copied into y causing incrementation 
  for(a = x; *a != '\0'; a++) {
    //leave it as empty statement
    ;
  }
    for(b = y, i = 0; i < num; i++, a++, b++) {
      *a = *b;
    }
  *a = '\0';
  return x;
}

/* 
Test Case 1: 
Input string: Test

string_copy returned Test
string_copy2 returned Test
2 number of elements returned from strn_copy Te
2 number of elements returned from strn_copy2 Te
str_cat returned TeTest
str_cat2 returned TeTestTest
2 number of concatenated elements returned strn_cat TeTestTestTe
2 number of concatenated elements returned strn_cat2 TeTestTestTeTe

Test Case 2: 
Input string: Applepie 

string_copy returned Applepie
string_copy2 returned Applepie
5 number of elements returned from strn_copy Apple
5 number of elements returned from strn_copy2 Apple
str_cat returned AppleApplepie
str_cat2 returned AppleApplepieApplepie
5 number of concatenated elements returned strn_cat AppleApplepieApplepieApple
5 number of concatenated elements returned strn_cat2 AppleApplepieApplepieAppleApple

Test Case 3:
Input string: Homework

string_copy returned Homework
string_copy2 returned Homework
4 number of elements returned from strn_copy Home
4 number of elements returned from strn_copy2 Home
str_cat returned HomeHomework
str_cat2 returned HomeHomeworkHomework
4 number of concatenated elements returned strn_cat HomeHomeworkHomeworkHome
4 number of concatenated elements returned strn_cat2 HomeHomeworkHomeworkHomeHome

Test Case 4:
Input string: catdog

string_copy returned catdog
string_copy2 returned catdog
3 number of elements returned from strn_copy cat
3 number of elements returned from strn_copy2 cat
str_cat returned catcatdog
str_cat2 returned catcatdogcatdog
3 number of concatenated elements returned strn_cat catcatdogcatdogcat
3 number of concatenated elements returned strn_cat2 catcatdogcatdogcatcat
*/ 