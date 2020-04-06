/* 
Reference for question I asked on stackoverflow 
https://stackoverflow.com/questions/60717542/c-program-pig-latin-translator-errors-how-to-fix-the-errors?noredirect=1#comment107435275_60717542 
*/ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//function to handle vowels  
bool isVowel(char v);

int main()
{
  //maximum character length of 50
  char word[50] = ""; 
  int i;

  printf("Pig Latin Translator\n");
  printf("----------------------\n");
  printf("Type a word: ");
  scanf("%s", word);

  //function toupper converts lowercase to uppercase 
  //increments till reaches 'y' character
  if (toupper(word[i]) == 'Y')
    i++;
  //iterates through if no vowel found and searches for 'QU' combination in the word  
  for (i; !isVowel(word[i]) && word[i] != '\0'; i++)
  {
    if (toupper(word[i]) == 'Q' && toupper(word[i + 1]) == 'U')
      i++;
  }
  
  //appends string from word and which number of characters are going to be appended
  //and i represents max number of characters to be appended 
  strncat(word, word, i);
  //copies the string pointed by the source 
  strcpy(word, &word[i]);

  //adds 'yay' to end word if first character(i) is a vowel, if not adds 'ay'
  if(i == 0) {
    strcat(word, "yay");
  } else {
    strcat(word,"ay");
  }
  printf("%s", word);
  return 0;
}

bool isVowel(char v) { 
  return strchr("AEIOUY", toupper(v)); 
}

/* 
Test case 1:
Pig Latin Translator
----------------------
Type a word: RHYME
YMERHay

Test case 2: 
Pig Latin Translator
----------------------
Type a word: rhyme
ymerhay

Test case 3: 
Pig Latin Translator
----------------------
Type a word: example
exampleyay

Test case 4: 
Pig Latin Translator
----------------------
Type a word: quiz
izquay

*/