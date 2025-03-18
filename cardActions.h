#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool contains(int arr[], int size, int value);
void dealCards(int cards[], int deck[], int *nextCard);
void shuffleDeck(int deck[]);
void showTable();
void showDeck(int deck[], int deckSize);
void whatCardIs(int card);
void showTableCards(int communityCards[], int numCommunityCards);
void addCommunityCard(int communityCards[], int *numCommunityCards, int deck[], int *nextCard);
int evaluateHand(int communityCards[], int handCards[]);
