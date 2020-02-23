#include <stdio.h>
#include <stdlib.h> 

void printPyramid(int n) {
    int x, y;
    printf("Output:\n");

    for (int i = x = 1; i <= n; i++)
    {
        //y = to the numbers increment of i and x and subtract 1
        y = x + i - 1;
        for (int j = 1; j <= i; j++)
        {
            //if row number is even, that number in the row output in reverse
            if (i % 2 == 0)
                printf("%d", y);
            //else numbers output as normal
            else
                printf("%d", x);
            //if j does not equal i, print the *
            if (j != i) {
                printf("*");
            }
            x++;
            y--;
        }
        //creates new line for rows
        printf("\n");
    }
}

int main() {
    int input;
    printf("To exit the program, enter a number <= 0\n");
    printf("Input : n = ");
    scanf_s("%d", &input);
    //type number less than 0 to exit
    while (input > 0) {
        printPyramid(input);
        printf("\nInput : n = ");
        scanf_s("%d", &input);
    }
    printf("See ya later!");
    return 0;
}

/*
Sample Test: 
To exit the program, enter a number <= 0
Input : n = 5
Output:
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15

Input : n = 4
Output:
1
3*2
4*5*6
10*9*8*7

Input : n = 15
Output:
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
21*20*19*18*17*16
22*23*24*25*26*27*28
36*35*34*33*32*31*30*29
37*38*39*40*41*42*43*44*45
55*54*53*52*51*50*49*48*47*46
56*57*58*59*60*61*62*63*64*65*66
78*77*76*75*74*73*72*71*70*69*68*67
79*80*81*82*83*84*85*86*87*88*89*90*91
105*104*103*102*101*100*99*98*97*96*95*94*93*92
106*107*108*109*110*111*112*113*114*115*116*117*118*119*120

Input : n = 0
See ya later!
*/