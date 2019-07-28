//randomtestcard1.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "math.h" 
#include <stdlib.h>
#include <time.h>

int baronTest(struct gameState *state, int choice1); 

//RANDOM TEST GENERATOR FROM CASE BARON
int main() {
	//declare variables from initalizeGame function
	int numPlayers;
	int kingdomCards[10] = {minion, ambassador, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	int randomSeed;
	struct gameState state;
	int choice1; 
	
	//seed time
	srand(time(0));
	
	//initalize randomSeed equal to a random number
	randomSeed = rand(); 
	
	//generate a random numPlayers between 1 and 4
	numPlayers = (rand() % (4 - 1 + 1)) + 1; 
	
	//initialize game
	initializeGame(numPlayers, kingdomCards, randomSeed, &state); 
	
	//randomize card deck 
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < sizeof(struct gameState); j++) {
			((char *)&state)[j] = rand % 256; 
		}
	}
	
		//generate random choice between 0 or 1; 
		choice1 = (rand() % (1 - 0 + 1)) + 0; 
	
		//generate a random currentPlayer from 0 to 3; 
		currentPlayer = (rand() % (3 - 0 + 1)) + 0; 
	
		//estate card supply set between 0 and 12 cards
		state.supplyCount[estate] = (rand() % (13 - 0 + 1)) + 0;
	
		//randomize discardCount between 0 and 500
		state.discardCount[currentPlayer] = rand() % (500 - 0 + 1) + 0;
	
		//randomize discardCount between 0 and 500	
		state.handCount[currentPlayer] = rand() % (500 - 0 + 1) + 0;
	
		handCount = state.handCount[currentPlayer]; 
		
		//function call to baronTest 
		baronTest(&state, choice1);
	
	
	return 0; 	
}

//CASE BARON
int baronTest(struct gameState *state, int choice1) {
	int currentPlayer = whoseTurn(state);
	int p = 0;//Iterator for hand!
	
	//previous gameState
	struct gameState prevState;
	
	//function call to baronRefactor
	baronRefactor(state, choice1);
	
	prevState.numBuys++;//Increase buys by 1!
	
	if(choice1 == 0) {
		prevState.discard[currentPlayer][prevState.discardCount[currentPlayer]] = estate;
		prevState.discardCount[currentPlayer]++;
		prevState.supplyCount[estate]--;
	}
	
	else if {
		prevState.coins = prevState.coins + 4;
		prevState.discard[currentPlayer][prevState.discardCount[currentPlayer]] = prevState.hand[currentPlayer][p];
		prevState.discardCount[currentPlayer]++;
		for (;p < prevState.handCount[currentPlayer]; p++){
	      		prevState.hand[currentPlayer][p] = prevState.hand[currentPlayer][p+1];
	    	}
		
	prevState.hand[currentPlayer][prevState.handCount[currentPlayer]] = -1;
	prevState.handCount[currentPlayer]--;
	}

	return 0;
}

     
