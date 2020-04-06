/* 
Citing what I used for help on stackoverflow for this program: 
https://stackoverflow.com/questions/13213422/count-the-number-of-occurrences-of-each-letter-in-string
https://stackoverflow.com/questions/12698836/counting-words-in-a-string-c-programming
https://stackoverflow.com/questions/61053200/how-to-find-unique-word-number-of-occurrences
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_CHAR 500

//function reads several lines of text and prints table indicating number of occurrences for a letter
void numberOfLetterOccurrences(char str[MAX_CHAR]); 
//function reads several lines of text and prints table indicating number of occurences for a specific length of word 
void lengthOfWord(char str[MAX_CHAR]);
//function reads several lines of text and prints table indicating number of occurrences of each different word 
void numberOfWordOccurrences(char str[MAX_CHAR]);

int main(void) {

  //introduction
  printf("STRING MANIPULATION PROGRAM\n");
  printf("---------------------------\n\n");

  //initialization for the string to be entered 
  char str[MAX_CHAR];
  int count; 
  //reader 
  printf("Type a sentence: "); 
  scanf("%[^\n]", (str));
  
  //making all entries lowercase
  for(int count = 0; str[count]; count++) {
   if('A' <= str[count] && 'Z' >= str[count]) {
     str[count] = tolower(str[count]);
   }
  }
  //functions that will modify the inputted string 
  numberOfLetterOccurrences(str);
  lengthOfWord(str);
  numberOfWordOccurrences(str);
}


void numberOfLetterOccurrences(char str[MAX_CHAR]) {
  //printing table format 
  printf("\n");
  printf("Alphabetical Letter | Number of Occurences");
  printf("\n");
  printf("-------------------------------------------\n");

  int count; 
  //array of all 26 letters in alphabet 
  char alphabet[26][2]; 
  //iterates through all letters in alphabet 
  for(count = 0; count < 26; count++) {
    //ASCII starts lower case alphabet at 97
    alphabet[count][0] = 97 + count;
    //count 
    alphabet[count][1] = 0;
  }
  //iterates through characters in string and handles letters lower case letters 
  for(count = 0; count < strlen(str); count++) {
    if('a' <= str[count] && 'z' >= str[count]) {
      alphabet[str[count] - 97][1]++;
    }
  }
  //iterates through all letters to print out the result of function 
  for (count = 0; count < 26; count++) {
        printf("%-21c%d\n", alphabet[count][0], alphabet[count][1]);
    }
}


void lengthOfWord(char str[MAX_CHAR]) {
  //printing table format
  printf("\n");
  printf("Length of Word | Number of Occurences"); 
  printf("\n");
  printf("-----------------------------------\n");

  int count; 
  //initalize array for handling the word and the count 
  int wordLength[20][2];

  //iterates through every individual word only upto the length of 20 and handles word length and count
  for(count = 0; count < 20; count++) {
    wordLength[count][0] = count + 1;
    wordLength[count][1] = 0;
  }
  //begin tokenizing sentence 
  char*tokenPtr = strtok(str, " ");

  //continue tokenizing sentence until tokenPtr becomes NULL 
  while(tokenPtr != NULL) {
    //length of current token 
    int len = strlen(tokenPtr); 
    //count of the word increments if word length less than or equal to 20 
    if(len <= 20) {
      wordLength[len - 1][1]++;
    }
    //get next token 
    tokenPtr = strtok(NULL, " ");
  }
  //iterates through all words to print out result of function 
  for(count = 0; count < 20; count++) {
    printf("%d\t\t\t    %d\n", wordLength[count][0], wordLength[count][1]); 
  }
}

void numberOfWordOccurrences(char str[MAX_CHAR]) {
  //printing table format
  printf("\n");
  printf("Unique Word | Number of Occurences"); 
  printf("\n");
  printf("-----------------------------------\n");

  int count = 0, i = 0;
  //declare 2d array to handle each unique word 
  char uniqueWord[99][999];
  //declare array to handle count 
  int wordList[99] = {0};
  //loop through until result becomes NULL 
  while(str[i] != '\0') {
    size_t j = 0;
    //array to handle unique token 
    char token[999]; 
    //tokenizes string and makes copy 
    while(str[i] != '\0' && str[i] != ' ') {
      token[j++] = str[i++];
    }
    //handles punctuation mark at the end of words 
    if(token[j - 1] == ':' || token[j - 1] == ',' || token[j - 1] == '.' || token[j - 1] == ';' || token[j - 1] == '?' || token[j - 1] == '!') {
      //instead of punctuation mark, turns it into null character 
      token[j - 1] = '\0';
    }
    //null 
    token[j] = '\0';
    //flag 
    int flag = -1; 
    //iterates through all words 
    for(j = 0; j < count; j++) {
      //handles current word in iteration
      if(strcmp(uniqueWord[j], token) == 0) {
        //if flag is valid, then...
        flag = j;
        wordList[flag] = wordList[flag] + 1;
        break;
      }
    }
    //if flag is invalid, then count increments and copy unique token into list 
    if(flag <= 1) {
      wordList[count] = wordList[count] + 1;
      strcpy(uniqueWord[count++], token);
    }
    i++;
  }
  //iterate through count of words in sentence 
  for(i = 0; i < count; i++) {
    printf("%-13s%d\n", uniqueWord[i], wordList[i]);
  }
}

/* 
Test Case 1: 

STRING MANIPULATION PROGRAM
---------------------------

Type a sentence: Hello there. Today is a good day because it is a Saturday. 

Alphabetical Letter | Number of Occurences
-------------------------------------------
a                    7
b                    1
c                    1
d                    4
e                    5
f                    0
g                    1
h                    2
i                    3
j                    0
k                    0
l                    2
m                    0
n                    0
o                    4
p                    0
q                    0
r                    2
s                    4
t                    4
u                    2
v                    0
w                    0
x                    0
y                    3
z                    0

Length of Word | Number of Occurences
-----------------------------------
1               2
2               3
3               1
4               1
5               2
6               1
7               1
8               0
9               1
10              0
11              0
12              0
13              0
14              0
15              0
16              0
17              0
18              0
19              0
20              0

Unique Word | Number of Occurences
-----------------------------------
hello        1
there        1
today        1
is           2
a            2
good         1
day          1
because      1
it           1
saturday     1

Test Case 2: 
STRING MANIPULATION PROGRAM
---------------------------

Type a sentence: This is an example of just a testing sentence. No other means to it.

Alphabetical Letter | Number of Occurences
-------------------------------------------
a                    4
b                    0
c                    1
d                    0
e                    8
f                    1
g                    1
h                    2
i                    4
j                    1
k                    0
l                    1
m                    2
n                    6
o                    4
p                    1
q                    0
r                    1
s                    6
t                    8
u                    1
v                    0
w                    0
x                    1
y                    0
z                    0

Length of Word | Number of Occurences
-----------------------------------
1               1
2               5
3               1
4               2
5               2
6               0
7               2
8               0
9               1
10              0
11              0
12              0
13              0
14              0
15              0
16              0
17              0
18              0
19              0
20              0

Unique Word | Number of Occurences
-----------------------------------
this         1
is           1
an           1
example      1
of           1
just         1
a            1
testing      1
sentence     1
no           1
other        1
means        1
to           1
it           1

Test Case 3: 
STRING MANIPULATION PROGRAM
---------------------------

Type a sentence: Roses are red. Violets are blue. Here I am, just passing through. 

Alphabetical Letter | Number of Occurences
-------------------------------------------
a                    4
b                    1
c                    0
d                    1
e                    8
f                    0
g                    2
h                    3
i                    3
j                    1
k                    0
l                    2
m                    1
n                    1
o                    3
p                    1
q                    0
r                    6
s                    6
t                    3
u                    3
v                    1
w                    0
x                    0
y                    0
z                    0

Length of Word | Number of Occurences
-----------------------------------
1               1
2               0
3               3
4               3
5               2
6               0
7               2
8               1
9               0
10              0
11              0
12              0
13              0
14              0
15              0
16              0
17              0
18              0
19              0
20              0

Unique Word | Number of Occurences
-----------------------------------
roses        1
are          2
red          1
violets      1
are          1
blue         1
here         1
i            1
am           1
just         1
passing      1
through      1

Test Case 4: 
STRING MANIPULATION PROGRAM
---------------------------

Type a sentence: How much wood could a woodchuck chuck if a woodchuck could chuck wood? As much as a woodchuck could chuck, if a woodchuck could chuck wood. 

Alphabetical Letter | Number of Occurences
-------------------------------------------
a                    6
b                    0
c                    22
d                    11
e                    0
f                    2
g                    0
h                    11
i                    2
j                    0
k                    8
l                    4
m                    2
n                    0
o                    19
p                    0
q                    0
r                    0
s                    2
t                    0
u                    14
v                    0
w                    8
x                    0
y                    0
z                    0

Length of Word | Number of Occurences
-----------------------------------
1               4
2               4
3               1
4               3
5               9
6               1
7               0
8               0
9               4
10              0
11              0
12              0
13              0
14              0
15              0
16              0
17              0
18              0
19              0
20              0

Unique Word | Number of Occurences
-----------------------------------
how          1
much         2
wood         3
could        4
a            4
woodchuck    4
chuck        4
if           2
as           2
much         1
*/