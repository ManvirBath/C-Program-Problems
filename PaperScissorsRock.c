#include <stdio.h>
#include <stdlib.h> 
#include<time.h> 

int main() {
    //character type for player1 since only accepts p,r,s
    char player1;   
    //integer type for player2 since only accepts 1,2,3
    int player2;    
    //integer type scores start at 0 
    int userScore = 0, cpuScore = 0;    
    srand((int)time(NULL));
    int count = 0;
    //iterates until count reaches 10
    while (count < 10) {
        printf("Enter p for Paper, r for rock, or s for scissor:\n");
        //using fgets() for reading char, instead of scanf
        fgets(&player1, 80, stdin); 
        //generate random number use
        player2 = rand() % 3 + 1;
        //if statements for all conditions if user or cpu wins the round or draw
         if (player1 == 'P' && player2 == 1 || player1 == 'p' && player2 == 1) {
            printf("Draw!\n");
        }if (player1 == 'P' && player2 == 2 || player1 == 'p' && player2 == 2) {
            userScore++;
            printf("User won this one!\n");
        }if (player1 == 'P' && player2 == 3 || player1 == 'p' && player2 == 3) {
            cpuScore++;
            printf("CPU won this one!\n");
        }if (player1 == 'R' && player2 == 2 || player1 == 'r' && player2 == 2) {
            printf("Draw!\n");
        }if (player1 == 'R' && player2 == 3 || player1 == 'r' && player2 == 3) {
            userScore++;
            printf("User won this one!\n");
        }if (player1 == 'R' && player2 == 1 || player1 == 'r' && player2 == 1) {
            cpuScore++;
            printf("CPU won this one!\n");
        }if (player1 == 'S' && player2 == 3 || player1 == 's' && player2 == 3) {
            printf("Draw!\n");
        }if (player1 == 'S' && player2 == 1 || player1 == 's' && player2 == 1) {
            userScore++;
            printf("User won this one!\n");
        }if (player1 == 'S' && player2 == 2 || player1 == 's' && player2 == 2) {
            cpuScore++;
            printf("CPU won this one!\n");
        }
        //updated score for every turn. invalid input ignored
        printf("User Score: %d\n", userScore);
        printf("CPU Score: %d\n\n", cpuScore);
        //increment every if statement even if invalid input
        count++;
    }
    //calculations for who wins at the end of the match out of 10 turns
    if (userScore == cpuScore) {
        printf("\nDraw game!");
    }
    else if (userScore > cpuScore) {
        printf("\nYou win!");
    }
    else {
        printf("\nCPU wins!");
    }
}

/*
Enter p for Paper, r for rock, or s for scissor:
R
Draw!
User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
P
Draw!
User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
P
Draw!
User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
R
Draw!
User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
S
Draw!
User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
P
User won this one!
User Score: 1
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
R
CPU won this one!
User Score: 1
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:

User Score: 1
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:
P
User won this one!
User Score: 2
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:
R
User won this one!
User Score: 3
CPU Score: 1


You win!


Sample Test 2: 
Enter p for Paper, r for rock, or s for scissor:

User Score: 0
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
p
User won this one!
User Score: 1
CPU Score: 0

Enter p for Paper, r for rock, or s for scissor:
r
CPU won this one!
User Score: 1
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:
S
Draw!
User Score: 1
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:
R
Draw!
User Score: 1
CPU Score: 1

Enter p for Paper, r for rock, or s for scissor:
P
CPU won this one!
User Score: 1
CPU Score: 2

Enter p for Paper, r for rock, or s for scissor:
S
User won this one!
User Score: 2
CPU Score: 2

Enter p for Paper, r for rock, or s for scissor:

User Score: 2
CPU Score: 2

Enter p for Paper, r for rock, or s for scissor:
P
Draw!
User Score: 2
CPU Score: 2

Enter p for Paper, r for rock, or s for scissor:
r
CPU won this one!
User Score: 2
CPU Score: 3

CPU wins!
*/