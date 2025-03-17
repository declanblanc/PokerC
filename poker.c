#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char *suits_str[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", 
                       "J", "Q", "K", "A"};

void dealCards(int cards[]) {

	srand(time(0));
	for(int i=0; i<2; i++) {
		cards[i] = (rand() % 52); 
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
	}


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
    	printf("Card %d is the %s of %s\n", i, faces_str[face], suits_str[suit]);
	}
}

void whatCardIs(int card) {
    int suit = card / 13;
    int face = card % 13;
    printf("Card %d is the %s of %s\n", card, faces_str[face], suits_str[suit]);
}

int main() {
	
	printf("Welcome to the poker table!\n");
	//showTable();
	
	int deck[52];
	for (int i = 0; i < 52; i++) {
		/* start with a sorted deck */
		deck[i] = i;
	}


	shuffleDeck(deck);

	//showDeck(deck, sizeof(deck)/sizeof(deck[0]));

	// I've created a deck of cards, how should I now use this deck? I don't even really need a deck. What I could use instead is a list of "cards in play". Rather than storing the entire deck as an array and worrying about updating that array everytime something changes, I can instead just deal cards as random values 0-51 and when one of those values is chosen, add it to an array of dealt cards so the next time we need a random card we just make sure it's not one of the dealt cards?
	int myCards[2] = { 0, 0 };
	dealCards(myCards);		
		
	printf("Your cards are: \n");
	for(int i = 0; i<2; i++) {
		printf("%d\n", myCards[i]);
		whatCardIs(myCards[i]);
	}

	return 0;
}
