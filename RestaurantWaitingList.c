#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 12
#define MAX_LENGTH 25

//waitlist for names/party
char waitList[MAX_SIZE][MAX_LENGTH];
//size of the party
char numberInParty[MAX_SIZE];
//counter
int count = 0; 

//declare the insert function
void insertList();
//declare the remove function
void removeList();
//declare the show list function
void showList(); 


int main(void) {
  while(1) {
    printf("\nResturant Waiting List\n");
    printf("-----------------------\n");
    printf("1. Add a party to the list\n");
    printf("2. Remove party off list\n");
    printf("3. Show list\n");
    printf("4. Quit\n");

    int reader;
    scanf("%d", &reader);
    //switch statement deals with all the cases for user's input and calls a function of choice
    //or quits 
    switch(reader) {
      case 1:
        insertList();
        break;

      case 2:
        removeList();
        break;

      case 3:
        showList();
        break;

      case 4:
        printf("Bye!");
        return EXIT_SUCCESS;
      default: 
        printf("That is not one of the choices.");
        return EXIT_FAILURE;     
    }
  }
}

void insertList() {
  char name[MAX_LENGTH];
  int number;
  int length = sizeof(waitList)/sizeof(waitList[0]);
  //ask for name
  printf("Name? ");
  scanf("%s", name);
  //checks if name is already used 
  for (int i = 0; i < length ; i++ ) {
    if (strcmp(waitList[i], name) == 0 ) {
        printf("Name already exists. Please enter another: ");
        scanf("%s", name);
    }
}
  //ask for how many are in person's party 
  printf("Number of people in party? ");
  scanf("%d", &number);
  
  //copies the inputted name to the waitlist count
  strcpy(waitList[count], name); 
  numberInParty[count] = number;
  printf("Inserted\n");
  //increments count to keep track everytime someone is added into waitlist 
  count++;

  //max people allowed is 12
  if(count > MAX_SIZE) {
    printf("Max capacity! Apologies, we're all booked up for right now.\n");
    printf("Feel free to come back later.");
  }
}

void removeList() {
  int number, i, j;
  //flag to keep count if condition is true
  int seatLocated;

  //checking if there is actually a name in waitlist or not before proceeding 
  if(count > 0) {
    printf("Table is ready. What is the size of the party? ");
    scanf("%d", &number);
    //if size of the party matches current user input with the input that is already in waitlist
    //then print the statement that table is ready 
    for(i = 0; i < count; i++) {
      if(number == numberInParty[i]) {
        //flag only increments if match is found true 
        seatLocated++;
        printf("%s(party size %d) is ready to be seated\n", waitList[i], numberInParty[i]);
        //this moves the position in waitlist for the person that was after the one 
        //that just were seated, so they move higher priority in the list 
        for(j = i + 1; j < MAX_SIZE; j++) {
          strcpy(waitList[i],waitList[j]);
          numberInParty[i] = numberInParty[j];
          i++;
        }
        //removes person from waitlist 
        count--;
        break;
      }
    }
  }
  //extra credit to check if table size is equal to a party 
  if(seatLocated == 0) {
    for(i = 0; i < count; i++) {
      if(number == numberInParty[i]) {
        //flag becomes 1 if condition passes true 
        seatLocated = 1;
        printf("%s(party size %d) is ready to be seated\n", waitList[i],numberInParty[i]);
        //this moves the position in waitlist for the person that was after the one 
        //that just were seated, so they move higher priority in the list 
        for(j = i + 1; j < MAX_SIZE; j++) {
          strcpy(waitList[i], waitList[j]);
          numberInParty[i] = numberInParty[j];
          i++;
        }
        count--;
        break;
      }
    }
  } else if(seatLocated == 0){
      //prints this if flag of seatLocated does not change 
      printf("Table of this size unavailable.");
  }
}

void showList() {
  int i;
  printf("Waitlist: %d parties",count);
  printf("\n");
  //iterates through the list and lists name/party size only if waitlist is not empty
  for(i = 0; i < count; i++) {
    if(waitList[i][0] != '\0') {
      printf("%s with party of %d\n",waitList[i],numberInParty[i]);
    }
  }
}

/*
Test case 1:
Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Rachel
Number of people in party? 8
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Sam
Number of people in party? 4
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
3
Waitlist: 2 parties
Rachel with party of 8
Sam with party of 4

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
2
Table is ready. What is the size of the party? 4
Sam(party size 4) is ready to be seated

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
3
Waitlist: 1 parties
Rachel with party of 8

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
4
Bye!

Test case 2:
Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Lou
Number of people in party? 9
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
3
Waitlist: 1 parties
Lou with party of 9

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Kobe
Number of people in party? 4
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
3
Waitlist: 2 parties
Lou with party of 9
Kobe with party of 4

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
4
Bye!

Test case 3: 

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Manvir
Number of people in party? 3
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
1
Name? Manvir
Name already exists. Please enter another: Raj
Number of people in party? 4
Inserted

Resturant Waiting List
-----------------------
1. Add a party to the list
2. Remove party off list
3. Show list
4. Quit
4
Bye
*/