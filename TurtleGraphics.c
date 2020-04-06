//the 3 focuses are the position, direction, and size of floor 
#include <stdio.h>

//defining symbolic constant FLOOR value of 50 
#define FLOOR_SIZE 50
//defining position of x and y
#define POSITION 20

enum PenPosition {down, up}; 
void movement(const int direction, const int penPosition);
int reader(void);
int moveDirection(int direction);
void printTurtleDrawing(void); 

//declared as global variables to be used throughout whole program
//MAX floorsize of 50 intialized to 0
int floorSize[FLOOR_SIZE][FLOOR_SIZE] = { {0} };
//starting position of x and y near center of the floor 
int positionX = POSITION;
int positionY = POSITION;

int main() {
  int read;
  int penPosition = down;
  //handles the direction of the turtle drawings in degrees
  int direction = 0;

  while(1) {
    read = reader();
    //using switch statement to deal with commands 
    switch(read) {

      //pen up
      case 1: 
      penPosition = down;
      break;

      //pen down
      case 2: 
      penPosition = up;
      break;
      
      //turn right
      case 3:
      direction = direction - 90;
      direction = moveDirection(direction); 
      break;
      
      //turn left
      case 4: 
      direction = direction + 90;
      direction = moveDirection(direction);
      break;

      //move forward
      case 5: 
      movement(direction, penPosition);
      break;

      //print drawing 
      case 6: 
      printTurtleDrawing();
      break;

      //end of data (sentinel)
      case 9:
      return 0;

      default: 
      printf("Incorrect command! Only pick a command from the options above\n");
    }
  }
}

//function that prints out drawing 
void printTurtleDrawing() {
  int i, j;
  //loop to iterate till MAX(50) of array starting from 0
  for(i = 0; i < FLOOR_SIZE; i++) {
  for(j = 0; j < FLOOR_SIZE; j++) 
    if(floorSize[i][j] == 1) {
      printf("*");
    } else {
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}

//function that handles the direction
void movement(const int direction, const int penPosition) {
  int i;
  int move;
  int moveX, moveY;
  
  //forward movement 
  if(direction == 0) {
    moveX = 1; moveY = 0;
    //upward movement 
  } else if(direction == 90) {
    moveX = 0; moveY = -1;
    //backward movement 
  } else if(direction == 180) {
    moveX = -1; moveY = 0;
    //downward movement 
  } else if(direction == 270) {
    moveX = 0; moveY = 1;
  }
  printf("How many space(s) would you like to move? ");
  scanf("%d", &move);

  for(i = 0; i < move; i++) {
    //deals with the moves of the x position 
    positionX = positionX + moveX;
    if(positionX <= 1) {
      positionX = 0;
    } else if(positionX > FLOOR_SIZE) {
      positionX = FLOOR_SIZE;
    }
    //deals with the moves of the y position 
    positionY = positionY + moveY;

    if(positionY < 0) {
      positionY = 0;
    } else if(positionY > FLOOR_SIZE) {
      positionY = FLOOR_SIZE;
    }
    if(penPosition == up) {
      floorSize[positionY][positionX] = 1;
    }
  }
}

//function where input is read from 
int reader(void) {
  int input;
  //prints information on the commands and meanings
  printf(
  "\n1 Pen up\n"
  "2 Pen down\n"
  "3 Turn right\n"
  "4 Turn left\n"
  "5 Move forward 10 spaces(or a number other than 10)\n"
  "6 Print the 50-by-50 array\n"
  "9 End and exit\n"
  "\n Pick turtle command: " 
  );
  scanf("%d", &input);

  return input; 
}

//function handles direction to be drawn 
int moveDirection(int direction) {
  int shift; 
  //shifts left
  if(direction <= 1) {
    shift = direction + 360; 
  //shifts right 
  } else if(direction >= 360) {
    shift = direction - 360;
  } else {
  //stay put
    shift = direction;
  }
  return shift; 
}

/*
Test Case 1: 
  *************
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *           *
  *************

  Test Case 2: 

  *********************
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *********************

  Test Case 3:

  *********************
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *                   *
  *********************

*/