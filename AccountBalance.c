#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  //old master file 
  FILE *oldfPtr;
  //new master file 
  FILE *newfPtr;
  //transaction file 
  FILE *transfPtr;

  //name for the master file 
  char mName[50];
  //master account/balance and transaction account/balance 
  int mAccount;
  int tAccount;
  double mBalance;         
  double tBalance;            

    // prints message if file cannot be opened 
    if ((oldfPtr = fopen("oldmast.dat", "r")) == NULL) {
        printf("Error occured while opening oldmast.dat\n");
    }

    // prints message if file cannot be opened 
    if ((transfPtr = fopen("trans.dat", "r")) == NULL) {
        printf("Error occured while opening trans.dat\n");
    }

    // prints message if file cannot be opened 
    if ((newfPtr = fopen("newmast.dat", "r")) == NULL) {
        printf("Error occured while opening newmast.dat\n");
    }

    //returning the results 
    printf("Returned results:\n");  
    fscanf(transfPtr, "%d%lf", &tAccount, &tBalance);

    //iterate until reach end of the transaction file 
    while (!feof(transfPtr)) {
        //reads next record 
        fscanf(oldfPtr, "%d%[^0-9-]%lf", &mAccount, mName, &mBalance);
        //display amount of master file till reaches new acc 
        while (tAccount > mAccount && !feof(oldfPtr)) {
            fprintf(newfPtr, "%d %s %.2f\n", mAccount, mName, mBalance);
            printf("%d %s %.2f\n", mAccount, mName, mBalance);
            fscanf(oldfPtr, "%d%[^0-9-]%lf", &mAccount, mName, &mBalance);
        }
        // updates info if match found  
        if (tAccount == mAccount) {
            mBalance += tBalance;
            fprintf(newfPtr, "%d %s %.2f\n", mAccount, mName, mBalance);
            printf("%d %s %.2f\n", mAccount, mName, mBalance);
            //if file does not match 
        } else if (tAccount < mAccount) {
            printf("Transaction record does not match for %d account \n", tAccount);
            fprintf(newfPtr, "%d %s %.2f\n", mAccount, mName, mBalance);
            printf("%d %s %.2f\n", mAccount, mName, mBalance);
        } else {
            printf("Unmatched transaction record for account %d\n", tAccount);
        }
        fscanf(transfPtr, "%d%lf", &tAccount, &tBalance); 
    }
    //displays results 
    while (!feof(oldfPtr)) {
        fscanf(oldfPtr, "%d%[^0-9-]%lf", &mAccount, mName, &mBalance);
        fprintf(newfPtr, "%d %s %.2f\n", mAccount, mName, mBalance);
        printf("%d %s %.2f\n", mAccount, mName, mBalance);
    }
    //close files 
    fclose(oldfPtr);
    fclose(newfPtr);
    fclose(transfPtr);

    return 0;
}

/* 

Returned results:
100   Alan Jones   375.31
300   Mary Smith   89.30
Transaction record does not match for 400 account 
500   Sam Sharp   0.00
700   Suzy Green   -14.22
Unmatched transaction record for account 900

*/