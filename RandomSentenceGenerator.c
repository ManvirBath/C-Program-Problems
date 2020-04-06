#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 5
#define MAX_SENTENCES 20

//function that handles generating the random sentence 
char *randomSentenceGenerator();

//four array pointers to char of article, noun, verb, and preposition and declared as const to notify the compiler that values of variables should not be modified
const char *article[SIZE] = {"the","a","one","some","any"};
const char *noun[SIZE] = {"boy","girl","dog","town","car"};
const char *verb[SIZE] = {"drove","jumped","ran","walked","skipped"};
const char *preposition[SIZE] = {"to","from","over","under","on"};
int i;

int main(void) {
  srand(time(NULL));
  randomSentenceGenerator(article,noun,verb,preposition);
  return 0;
}

char *randomSentenceGenerator() {
  //iterates random sentences 20 times using rand() and SIZE is used to pick any of the 5 words within the array 
    for(i = 0; i < MAX_SENTENCES; i++) {
    printf("%s %s %s %s %s %s. \n", article[rand() % SIZE], noun[rand() % SIZE], verb[rand() % SIZE], preposition[rand() % SIZE], article[rand() % SIZE], noun[rand() % SIZE]);
  }
  return 0;
}

/* 
test case 1: 
some girl ran to some boy
a dog skipped from one dog
the car walked from the girl
one girl jumped under one car
one boy ran under one boy
any dog ran under any dog
some girl jumped over any town
a car skipped over some car
the boy walked from a boy
a town ran to a girl
the boy skipped over a boy
a car walked over any boy
one boy skipped over any car
some boy ran under a town
some car walked from any car
one boy jumped under any dog
a girl skipped on the boy
any town ran from one dog
one dog ran from a boy
a girl drove on any car

test case 2: 
any car jumped over a town. 
some car ran under a dog. 
the dog walked from a boy. 
a girl skipped on one girl. 
any girl drove on any dog. 
one boy jumped under any car. 
some car walked over one car. 
a car ran over a boy. 
one dog walked from one boy. 
one town jumped to one dog. 
one girl ran to a girl. 
a car ran on one dog. 
a boy jumped to one dog. 
the car drove under one car. 
some boy ran from one girl. 
any girl drove under some girl. 
one car jumped on the boy. 
a girl drove to some town. 
one boy skipped on some dog. 
the town skipped over one girl.
*/