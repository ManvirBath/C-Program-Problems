#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for employee such as the ID, Name and title of job 
struct employee {  
    int employeeID; 
    char name[25];
    char jobTitle[30];
}; 

//comparison function that determines sorting in descending order 
void sortRecords(struct employee records[], size_t size);

int main(void) {
  struct employee employeeRecord[50];
  char employees[20];
  unsigned int i, j, count = 0;
  int flag;

   printf("Employee Records Program");
   printf("\n");
   printf("-------------------------");
   printf("\n");

    flag = 1;
    while(flag != 0) {

    //input for employee name and putting it in the employee record book
    char name[25];
    printf("\nEnter name of employee: ");
    scanf("%s", name);
    strcpy(employeeRecord[count].name, name);

    //input for employee ID and inputting it in the employee record book 
    int ID; 
    printf("Enter the employee ID: "); 
    scanf("%d", &ID);
    employeeRecord[count].employeeID = ID;

    //input for employee job title and putting it in the employee record book
    char title[25];
    printf("Enter job title of employee: ");
    scanf("%s", title);
    strcpy(employeeRecord[count].jobTitle, title);
    //count increments everytime that goes through 
    count++;

    printf("\n");

    //option to add more employee
    char option[2];

    printf("Add employee? (Y/N): ");
    scanf("%s", option);

    //option to continue, but if record has less than 5 people when typing N, it will still iterate til that condition met 
    if((option[0] == 'n' || option[0] == 'N') && count < 5) {
        printf("Requirement of 5 employees in record book\n");
    } else if(option[0] == 'n' || option[0] == 'N') {
      flag--;
    } else if(option[0] == 'y' || option[0] == 'Y') {
      continue;
    }
  }

  sortRecords(employeeRecord, (count + 1));

  //printing result of the table 
  printf("\n");
  printf("Employee Record Book");
  printf("\n");
  printf("--------------------\n");
  printf("\n");
  printf("%-8s%-20s%-15s\n", "ID", "Name", "Job Title");
  printf("--------------------------------------------------");
  for (i = 0; i < count; i++)
    {
      printf("%-8d%-20s%-15s\n", employeeRecord[i].employeeID, employeeRecord[i].name, employeeRecord[i].jobTitle);
    }
  }

//comparison function that determines sorting in descending order 
void sortRecords(struct employee records[], size_t size) {

  struct employee Employee; 
  unsigned int i;
  size_t j;

  //loop to control passes
  for(i = 0; i < size; ++i) {
    //loop to control number of comparisons per pass 
    for(j = i + 1; j < size - 1; ++j) {
      if(strcmp(records[i].name, records[j].name) < 0) {
        //handles the swap to which employee name gets priority
        Employee = records[i];
        records[i] = records[j];
        records[j] = Employee;
      }
    }
  }
}

/*

Employee Records Program
-------------------------

Enter name of employee: Mike
Enter the employee ID: 12345 
Enter job title of employee: Firefighter

Add employee? (Y/N): N
Requirement of 5 employees in record book

Enter name of employee: Sally
Enter the employee ID: 48573
Enter job title of employee: Lawyer 

Add employee? (Y/N): Y

Enter name of employee: Sam
Enter the employee ID: 30485
Enter job title of employee: Teacher

Add employee? (Y/N): Y

Enter name of employee: Zara
Enter the employee ID: 98463
Enter job title of employee: Technician

Add employee? (Y/N): Y

Enter name of employee: Arya
Enter the employee ID: 74531
Enter job title of employee: Judge

Add employee? (Y/N): y

Enter name of employee: Mason
Enter the employee ID: 85943
Enter job title of employee: Astronaut

Add employee? (Y/N): Y

Enter name of employee: Macy
Enter the employee ID: 43512
Enter job title of employee: Counselor

Add employee? (Y/N): n

Employee Record Book
--------------------
ID      Name                Job Title      
--------------------------------------------------
98463   Zara                Technician     
30485   Sam                 Teacher        
48573   Sally               Lawyer         
12345   Mike                Firefighter    
85943   Mason               Astronaut      
43512   Macy                Counselor      
74531   Arya                Judge       

*/
