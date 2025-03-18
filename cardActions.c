#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DECK_SIZE 52
enum Hands {
	HIGH_CARD,
	PAIR,
	TWO_PAIR,
	THREE_OF,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};
// The suits are in the order: Spade, Heart, Diamond, Club
char *suits_str[4] = {"\u2660", "\u2661", "\u2662", "\u2663"}; 
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

bool contains(int arr[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return true;
    }
  }
  return false;
}

// Deals cards to a player's hand 
void dealCards(int cards[], int deck[], int *nextCard) {
	for(int i = 0; i<2; i++) {
		printf("In the delCards function the value of nextCard is: %d\n", *nextCard);
		cards[i] = deck[*nextCard];
		(*nextCard)++;
	}
}

void shuffleDeck(int deck[]) {
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
    	int from = (rand() % 52);
    	int to = (rand() % 52);
    	int card = deck[from];
    	deck[from] = deck[to];
    	deck[to] = card;
	}
}

void showTable() {

	bool emptyTable = true;
	printf("A card might look like: \n");
	
	printf(" _____ \n");
	printf("|A♤   |\n");
	printf("|     |\n");
	printf("|     |\n");
	printf("|___A♤|\n");

	printf("   _____________________________________________\n");
	printf("  /                                             \\\n");
	printf(" /                                               \\\n");
	printf("|                                                 |\n");

	if(emptyTable) {
		for(int i = 0; i < 5; i++) {
			printf("|                      ♤♧♡♢                       |\n");
		}
	} else {
		printf("");
		printf("|                                                 |\n");
	}

	printf("|                                                 |\n");
	printf("|                                                 |\n");
	printf(" \\                                               /\n");
	printf("  \\_____________________________________________/\n");

}
void showDeck(int deck[], int deckSize) {
	printf("Here is the deck:\n");
	for (int i = 0; i < deckSize; i++) {
    	int card = deck[i];
    	int suit = card / 13;
    	int face = card % 13;
    	printf("%2d: %2s of %s\n", i, faces_str[face], suits_str[suit]);
	}
}

void whatCardIs(int card) {
    int suit = card / 13;
    int face = card % 13;
    printf("Card %d is the %s of %s\n", card, faces_str[face], suits_str[suit]);
}
void showTableCards(int communityCards[], int numCommunityCards) {
	printf("The cards on the table are: \n");
	if (numCommunityCards == 0) {
		printf("There are no cards on the table yet\n");
	} else {
		for(int i = 0; i<numCommunityCards; i++) { 
			printf("%d\t", communityCards[i]);
			whatCardIs(communityCards[i]);
		}
		printf("\n");
	}
}
void addCommunityCard(int communityCards[], int *numCommunityCards, int deck[], int *nextCard) {
	if(*numCommunityCards >= 5) {
		printf("There are already 5 commnunity cards on the table!\n");
	} else {
		communityCards[(*numCommunityCards)++] = deck[(*nextCard)++];
	}
}

int evaluateHand(int communityCards[], int handCards[]) { 
	// handValue always starts at HIGH_CARD before being evaluated
	enum Hands handValue = HIGH_CARD;
	// A hand can only be five cards so first we check
	// handCards + communityCards[0-2]
	// Store the result of that combination
	// Then handCards + communityCards 1-3
	// etc.
	
	int *currentHand = malloc(5 * sizeof(int));		
	
	for(int i=0; i<3; i++) {
		memcpy(currentHand, handCards, 2*sizeof(int));
		memcpy(currentHand+2, communityCards+i, 3*sizeof(int));
		printf("The cards in hand %d are:\n", i);
		for(int j=0; j<5; j++) {
			printf("Card %2d is: %2d\n", j, currentHand[j]);
		}
	}

	return handValue;
}
