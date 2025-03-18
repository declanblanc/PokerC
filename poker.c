#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "cardActions.h"

int main() {
	
	printf("Welcome to the poker table!\n");
	
	int deck[52];
	int communityCards[5]; // Tracks the value of each community card.
	int numCommunityCards = 0; // Tracks how many community cards are in play.
	int nextCard = 0; // Tracks which card in the deck is next to be drawn.

	// Create a sorted deck.
	for (int i = 0; i < 52; i++) {
		deck[i] = i;
	}
	showDeck(deck, sizeof(deck)/sizeof(deck[0]));
	shuffleDeck(deck); // Shuffle the deck.
	showDeck(deck, sizeof(deck)/sizeof(deck[0])); // Confirm the deck is shuffled.

	/* I've created a deck of cards, how should I now use this deck? 

	   I don't even really need a deck. 
	   What I could use instead is a list of "cards in play". 
	   Rather than storing the entire deck as an array and worrying about updating that array everytime something changes, I can instead just deal cards as random values 0-51 and when one of those values is chosen, add it to an array of dealt cards so the next time we need a random card we just make sure it's not one of the dealt cards?

	   Alternatively rather than tracking which cards are in play. I could use a randomized deck.
	   1. Initialize the deck with card values 0-51
	   2. Shuffle the deck to create a random order
	   3. Each round, initalize nextCard = 0 
	   4. Any time a card is drawn, increment that value when drawing a card. deck[nextCard++]
	   
	   The max number of cards that will be in play any given round is 5 + ( 2 * playerCount )
	   I'm pretty sure there are some unique situations in poker where there may be more but I won't worry about that for this game.
	*/
	int myCards[2] = { 0, 0 };
	dealCards(myCards, deck, &nextCard);		
		
	printf("Your cards are: \n");
	for(int i = 0; i<2; i++) {
		printf("%d\n", myCards[i]);
		whatCardIs(myCards[i]);
	}

	printf("The next card in the deck is card #%d\n", nextCard);
	showTableCards(communityCards, numCommunityCards);
	
	// Flop
	addCommunityCard(communityCards, &numCommunityCards, deck, &nextCard);
	addCommunityCard(communityCards, &numCommunityCards, deck, &nextCard);
	addCommunityCard(communityCards, &numCommunityCards, deck, &nextCard);
	// Turn 
	addCommunityCard(communityCards, &numCommunityCards, deck, &nextCard);
	//River
	addCommunityCard(communityCards, &numCommunityCards, deck, &nextCard);
	
	showTableCards(communityCards, numCommunityCards);
	printf("The next card in the deck is card #%d\n", nextCard);

	// Now need a way to evaluate each hand. 
	// Each hand is myCards + communityCards 
	evaluateHand(communityCards, myCards);

	return 0;
}
