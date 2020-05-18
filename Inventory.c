#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//inventory structure def 
struct inventory {
  unsigned int number;
  char tool[25];
  int amount;
  double price;
};

//prototypes
unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(void) {
  //hardware.dat file pointer 
  FILE *cfPtr;
  cfPtr = fopen("hardware.dat", "rb+");

  fclose(cfPtr);

  //fopen opens the file; exits if file cannot be opened 
  if((cfPtr = fopen("hardware.dat", "rb+")) == NULL) {
    puts("File could not be opened.");
  } else {
    //user choice 
    unsigned int choice; 

    //enable user to specify action 
    while( (choice = enterChoice()) != 5 ) {
      switch(choice) {
        //create text file from record file 
        case 1: 
          textFile(cfPtr);
          break;
        //updates record
        case 2: 
          updateRecord(cfPtr);
          break;
        //new record
        case 3: 
          newRecord(cfPtr);
          break;
          //deletes record
        case 4: 
          deleteRecord(cfPtr);
          break;
          // if invalid choice 
        default: 
          puts("Incorrect choice\n");
          break;  
      }
    } 
    //fclose closes the file 
    fclose(cfPtr);  
  }
} 

//function handles printing 
void textFile(FILE *readPtr) {

  //hardware.txt file pointer
  FILE *writePtr;

  //fopens the file; exits if file can not be opened 
  if( (writePtr = fopen("hardware.txt", "w")) == NULL) {
    puts("File could not be opened");
  } else {
    //sets pointer to beginning of file 
    rewind(readPtr);
    fprintf(writePtr, "%-6s%-16s%-11s%9s\n", "Record #", "  Tool Name", "amount", "price");

    //copy all files from random access file to text file 
    while(!feof(readPtr)) {
      //create data with default information 
      struct inventory data = {0, "", 0, 0};

      int result = fread(&data, sizeof(struct inventory), 1, readPtr);

        //write single record to text file 
      if(result != 0 && data.number != 0) {
        fprintf(writePtr, "%-10d%-18s%-11d%1.2f\n", data.number,
        data.tool, data.amount,data.price);
      }     
    }
    //fclose closes the file
    fclose(writePtr);
  }
}

//function handles updating in record 
void updateRecord(FILE *fPtr) {
  
  //obtain number to update 
  printf("%s", "Enter the number of record to update (1 - 100):");
  //record number
  unsigned int record; 
  scanf("%d", &record);

  //move file pointer to correct record in file 
  fseek(fPtr, (record - 1)* sizeof(struct inventory), SEEK_SET);

  struct inventory data = {0, "", 0, 0}; 

  //read record from file 
  fread(&data, sizeof(struct inventory), 1, fPtr);

  //display error if it doesn't exist 
  if(data.number == 0) {
    printf("Error occured.\n");
    //update record 
  } else {
    printf("%-10d%-18s%-11d%1.2f\n", data.number,data.tool,data.amount, data.price);

      //request the amount to be updated 
      printf("%s", "Enter the updated amount: ");
      int nAmount;
      scanf("%d", &nAmount);
      //update amount 
      data.amount += nAmount; 
      printf("%-10d%-18s%-11d%1.2f\n", data.number,data.tool,data.amount, data.price);

      //move the file pointer to correct record in file
      fseek(fPtr, (record - 1) * sizeof(struct inventory), SEEK_SET);
      //write updated record over the old one in file 
      fwrite(&data, sizeof(struct inventory), 1, fPtr);
    }
}

//delete existing record 
void deleteRecord(FILE *fPtr) {
  //obtain the number of record to delete
    printf("%s", "Enter the record of number to delete (1 - 100): ");
    unsigned int dltNum;
    scanf("%d", &dltNum);

    //move file pointer to correct record in file
    fseek(fPtr, (dltNum - 1) * sizeof(struct inventory), SEEK_SET);

    struct inventory data;

    //reads record from the file 
    fread(&data, sizeof(struct inventory), 1, fPtr);

    //display error if record non-existent
    if (data.number == 0 ) {
      printf("Error while opening file.\n");
      //delete record
    } else {  
      //move file pointer to correct record in file 
      fseek(fPtr, (dltNum - 1) * sizeof(struct inventory), SEEK_SET);

      //blank 
      struct inventory blank = {0, "", 0, 0};

      //replace existing record with blank 
      fwrite(&blank, sizeof(struct inventory), 1, fPtr); 
    }
}

//create and insert record 
void newRecord(FILE *fPtr) {
  //obtain number of record to create 
  printf("%s","Enter new record number: ");
  unsigned int num;
  scanf("%d", &num);

  //move the file pointer to correct record in file 
  fseek(fPtr, (num - 1) * sizeof(struct inventory),SEEK_SET);

  //create data with default info 
  struct inventory data = { 0, "", 0, 0};

  //read record from file 
  fread(&data, sizeof(struct inventory), 1, fPtr);

  //display error if record already exists 
  if (data.number != 0) {
    printf("The record already exists.\n");
    //create record 
  } else {

    //input for name of tool
    printf("Enter the the name of the tool to be added: ");
    scanf("%s[^\n]", data.tool);

    //input for amount 
    printf("Enter amount of the tool to be added: ");
    scanf("%d", &data.amount);

    //input for the price
    printf("Enter price of the tool whose record to be added: ");
    scanf("%lf", &data.price);

    data.number = num;

    //move pointer to correct record in file
    fseek(fPtr, (data.number - 1) * sizeof(struct inventory), SEEK_SET);
    //insert record in file
    fwrite(&data, sizeof(struct inventory), 1, fPtr);
  }
}

//enable user to input choice 
unsigned int enterChoice(void) {
  unsigned int choice;
  printf("Enter choice\n"
  "1- store a formatted text file hardware.txt for printing\n"
  "2- update a record\n"
  "3- add a new record\n"
  "4- delete a record\n"
  "5- end program?\n ");

  scanf("%u", &choice);
  return choice;
}

/*

Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 3
Enter new record number: 1
Enter the the name of the tool to be added: Drill
Enter amount of the tool to be added: 1
Enter price of the tool whose record to be added: 15.32
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 1
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 4
Enter the record of number to delete (1 - 100): 1
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 1
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 2
Enter the number of record to update (1 - 100):3
3         Thermometer       2          99.99
Enter the updated amount 4
3         Thermometer       6          99.99
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end program?
 1
Enter choice
1- store a formatted text file hardware.txt for printing
2- update a record
3- add a new record
4- delete a record
5- end pr

hardware.txt
Record #  Tool Name     amount         price
2         Toolbox           5          50.00
3         Thermometer       6          99.99
6         Screwdriver       7          11.99
*/ 