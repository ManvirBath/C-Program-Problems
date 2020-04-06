// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5
#define SIZE 2

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wHand[][SIZE], unsigned int wDeck[][FACES], const char *wFace[],
   const char *wSuit[]); // dealing doesn't modify the arrays

//pair function handles if hand makes a pair or has two pairs 
void pair(unsigned int wHand[] [SIZE], const char *wFace[], const char *wSuit[]);
//threeOfAKind function handles if hand makes a three of a kind
void threeOfAKind(unsigned int wHand[] [SIZE], const char *wFace[], const char *wSuit[]);
//fourOfAKind function handles if hand makes a four of a kind 
void fourOfAKind(unsigned int wHand[] [SIZE], const char *wFace[], const char *wSuit[]);
//flush function handles if hand makes a flush 
void flush(unsigned int wHand[][SIZE], const char *wFace[], const char *wSuit[]);
//straight function handles if hand makes a straight 
void straight(unsigned int wHand[][SIZE], const char *wFace[], const char *wSuit[]);

int main(void)
{
  // initialize deck array
   unsigned int deck[SUITS][FACES] = {0};
   //poker hand 
   unsigned int hand[HAND][SIZE];
   //loops through rows of wDeck 
   for(size_t row = 0; row < SUITS; ++row) {
      //loops through columns of wDeck 
     for(size_t column = 0; column < FACES; ++column) {
       deck[row][column] = 0;
     }
   }

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                      
   const char *suit[SUITS] =           
      {"Hearts", "Diamonds", "Clubs", "Spades"};
  
   // initialize face array                  
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",        
       "Five", "Six", "Seven", "Eight",        
       "Nine", "Ten", "Jack", "Queen", "King"};

  deal(hand, deck, face, suit); //deal the deck

  //shows if hand turns out to be any pair(2 pair, three of a kind, and/or four of a kind), flush, or straight
  pair(hand, face, suit);
  threeOfAKind(hand, face, suit);
  fourOfAKind(hand, face, suit);
  flush(hand, face, suit);
  straight(hand, face, suit);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                       
         row = rand() % SUITS;                                  
         column = rand() % FACES;                            
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   }
}

// deal cards in deck
void deal(unsigned int wHand[][SIZE], unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]) {
  unsigned int position = 0; 
  printf("Poker Hand: \n\n");
  //deal each of the cards
  for (size_t card = 1; card <= HAND; ++card) {
    //loops through rows of wDeck
    for (size_t row = 0; row < SUITS; ++row) {
      //loop through columns of wDeck for current row 
      for (size_t column = 0; column < FACES; ++column) {
        //if slot contains current card, display card 
        if (wDeck[row][column] == card) {
        {
          wHand[position][0] = row;
          wHand[position][1] = column;
          printf("%s of %-8s\n", wFace[column], wSuit[row]);
          ++position;
          }
        }
      }
    }
  }
  printf("\n");
}

void pair(unsigned int wHand[][SIZE], const char *wFace[], const char *wSuit[]) {
  //reads if there's a pattern for face card in the hand 
  unsigned int pattern[FACES] = {0};
  size_t i, j;
  //reads value of cards 
  for (i = 0; i < HAND; ++i) {
    ++pattern[wHand[i][1]];
  }
  //only prints if the number if a pair or two pair is found 
  for (j = 0; j < FACES; ++j) {
    if (pattern[j] == SIZE) {
      printf("Pair of %ss.\n", wFace[j]);
    }
  }
}
void threeOfAKind(unsigned int wHand[] [SIZE], const char *wFace[], const char *wSuit[]) {
  //reads if there's a pattern for face card in the hand 
  unsigned int pattern[FACES] = {0};
  size_t i, j;
  //reads value of cards 
  for (i = 0; i < HAND; ++i) {
    ++pattern[wHand[i][1]];
  }
  //only prints if the number if a pair or two pair is found 
  for (j = 0; j < FACES; ++j) {
    if(pattern[j] == 3) {
      printf("Three of a Kind of %ss.\n",wFace[j]); 
    }
  }
}

void fourOfAKind(unsigned int wHand[] [SIZE], const char *wFace[], const char *wSuit[]) {
  //reads if there's a pattern for face card in the hand 
  unsigned int pattern[FACES] = {0};
  size_t i, j;
  //reads value of cards 
  for (i = 0; i < HAND; ++i) {
    ++pattern[wHand[i][1]];
  }
  //only prints if the number if a pair or two pair is found 
  for (j = 0; j < FACES; ++j) {
    //four of a kind 
    if(pattern[j] == 4) {
      printf("Four of a kind of %ss.\n",wFace[j]); 
    }
  }
}

void flush(unsigned int wHand[][SIZE], const char *wFace[], const char *wSuit[]) {
  //reads if there's a pattern for suits in the hand 
  unsigned int pattern[SUITS] = {0};
  size_t i, j; 
 //reads number of suits in the hand 
  for (i = 0; i < HAND; ++i) {
    ++pattern[wHand[i][0]];
  }
  //if ends up being 5 suits, prints out that it's a flush
  for (j = 0; j < SUITS; ++j) {
    if (pattern[j] == HAND) {
      printf("Flush of %ss.\n", wSuit[j]);
    }
  }
}

void straight(unsigned int wHand[][SIZE], const char *wFace[], const char *wSuit[]) {
  unsigned int array[HAND] = {0}; 
  for (size_t i = 0; i < HAND; ++i) {
    array[i] = wHand[i][1];
  }
  // sort an array of integers using bubble sort algorithm
  for (unsigned int pass = 1; pass < HAND; ++pass) {
    for (size_t j = 0; j < 4; ++j) {
      if (array[j] > array[j + 1]) {
        unsigned int hold = array[j];
        array[j] = array[j + 1];
        array[j + 1] = hold;
      }
    }
  }
  //logic for finding out if hand is a straight by making the first card equal to the second card to third card to fourth card
  if (array[0] == array[1] - 1 && array[1] == array[2] - 1 && array[2] == array[3] - 1 && array[3] == array[4] - 1) {
    printf("Straight of %s, %s, %s, %s, %s.\n", wFace[array[0]], wFace[array[1]], wFace[array[2]], wFace[array[3]], wFace[array[4]]);
  }
}

/* 
Test Case 1:
Poker Hand: 

Seven of Hearts  
Queen of Clubs   
Seven of Clubs   
Ace of Hearts  
King of Clubs   

Pair of Sevens.

Test Case 2:
Poker Hand: 

Eight of Spades  
Ace of Spades  
Ace of Diamonds
Ace of Hearts  
Nine of Hearts  

Three of a Kind of Aces.

Test Case 3:

Poker Hand: 

Ace of Clubs   
Seven of Clubs   
Ace of Spades  
Seven of Diamonds
Six of Hearts  

Pair of Aces.
Pair of Sevens.

Test Case 4: 

Poker Hand: 

Ace of Spades  
Four of Diamonds
Four of Clubs   
Four of Spades  
Ace of Hearts  

Pair of Aces.
Three of a Kind of Fours.

Test Case 5: 

Poker Hand: 

Ten of Spades  
Nine of Hearts  
Queen of Hearts  
Jack of Diamonds
King of Hearts  

Straight of Nine, Ten, Jack, Queen, King.

*/