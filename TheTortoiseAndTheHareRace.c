#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_SQUARE 1
#define MAX_SQUARE 70

//handles movetypes of tortoise 
void moveTortoise();
//handles movetypes of the hare 
void moveHare(); 
//prints current position 
void trackPosition(int tortoise, int hare);  

unsigned int tortoise = MIN_SQUARE;
unsigned int hare = MIN_SQUARE;
unsigned int ticktock = 0;

int main(void) {

  printf("The Tortoise and the Hare Race\n");
  printf("-------------------------------\n");
  printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n\n");

  //random number generator 
  srand(time(NULL));

  //handles and records the movetypes of the race until they reach/pass square 70
  while(tortoise < MAX_SQUARE && hare < MAX_SQUARE) {
        moveTortoise();
        moveHare();
        trackPosition(tortoise, hare);
        ticktock++;
    }
    
    //declaration of the champion 
    if(tortoise < hare) {
        printf("Hare wins. Yuch .\n");
    } else if(tortoise > hare) {
        printf("TORTOISE WINS!!! YAY!!!\n");
    } else if(tortoise == hare) {
        printf("It's a tie.\n");
    }
  return 0;
}

//adjust position of tortoise with each tick of the clock, use a scale of 1 - 100 to determine what percentage of time they're at for the chances of their move type  
void moveTortoise() {
  //fast plod, 3 squares forward 
  if((rand() % 100) + 1 >= 10 && (rand() % 100) + 1 <= 50) {
        tortoise += 3;
    }
    //slip, 6 squares backward
    else if((rand() % 100) + 1 >= 60 && (rand() % 100) + 1 <= 70) {
        tortoise -= 6;
    }
    //slow pod, 1 square forward 
    else if((rand() % 100) + 1 >= 80 && (rand() % 100) + 1 <= 100) {
        tortoise += 1;
    }
    
    if(tortoise < MIN_SQUARE) {
        tortoise = MIN_SQUARE;
    } else if(tortoise > MAX_SQUARE) {
        tortoise = MAX_SQUARE;
    }
}

//adjust position of hare with each tick of the clock, use a scale of 1 - 100 to determine what percentage of time they're at for the chances of their move type  
void moveHare() {
  //sleep, no move at all.. zzz..
  if((rand() % 100) + 1 >= 10 && ((rand() % 100) + 1) <= 20) {
    hare += 0;
    //big hop, 9 squares forward
  } else if((rand() % 100) + 1 >= 30 && (rand() % 100) + 1 <= 40) {
      hare += 9;
    //big slip, 12 squares backward
  } else if((rand() % 100) + 1 == 50) {
      hare -= 12;
    //small hop, 1 square forward
  } else if((rand() % 100) + 1 >= 60 && (rand() % 100) + 1 <= 80) {
      hare += 1;
    //small slip, 2 squares backward
  } else if((rand() % 100) + 1 >= 90 && (rand() % 100) + 1 <= 100) {
      hare -= 2;
  }
    
  if(hare < MIN_SQUARE) {
      hare = MIN_SQUARE;
  }
  else if(hare > MAX_SQUARE) {
      hare = MAX_SQUARE;
  }
}

void trackPosition(int tortoise, int hare) {
  unsigned int i;
  //tracks and handles calculations of the position of hare(H) compared to tortoise(T) when hare is leading in the race 
  if(hare > tortoise) {
    for(i = MIN_SQUARE; i < tortoise; i++) {
      printf("%s", " ");
      printf("T");
    }
    for(i = MIN_SQUARE; i < hare - tortoise; i++) {
      printf("%s"," ");
      printf("H");
    } 
    //tracks and handles calculations of the position of tortoise(T) compared to hare(H) when tortoise is leading in the race 
  } else if(tortoise > hare) {
      for(i = MIN_SQUARE; i < hare; i++) {
        printf("%s", " ");
        printf("H");
      }
      for(i = MIN_SQUARE; i < tortoise - hare; i++) {
        printf("%s", " ");
        printf("T");
      }
    //tracks and handles calculations when both are current in a tied position and prints OUCH instead of their indictator of H/T 
  } else if(tortoise == hare) {
      for(i = MIN_SQUARE; i < tortoise; i++) {
        printf("%s", " ");
        printf("OUCH!!!"); 
      }
    }
  printf("\n");
}

/*
Test case 1:

The Tortoise and the Hare Race
-------------------------------
BANG !!!!!
AND THEY'RE OFF !!!!!

H  T
H     T
H     T
H        T
H  T
         H                                                           T
TORTOISE WINS!!! YAY!!!

Test case 2:

The Tortoise and the Hare Race
-------------------------------
BANG !!!!!
AND THEY'RE OFF !!!!!

OUCH!!!
OUCH!!!
   T     H
      T  H
T         H
   T      H
      T    H
       T   H
          T         H
           T                 H
     T                                H
        T                             H
           T                           H
     T                                 H
        T                                       H
        T                                       H
        T                                       H
           T                                    H
           T                                     H
              T                                           H
              T                                                    H
                 T                                                   H
Hare wins. Yuch .

Test case 3: 

The Tortoise and the Hare Race
-------------------------------
BANG !!!!!
AND THEY'RE OFF !!!!!

OUCH!!!
                                                                     OUCH!!!
It's a tie.

*/