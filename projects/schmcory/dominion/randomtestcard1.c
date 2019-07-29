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

int baronTest(struct gameState *state, int choice1, int currentPlayer); 

//RANDOM TEST GENERATOR FROM CASE BARON
int main() {
	//declare variables from initalizeGame function
	int numPlayers;
	int kingdomCards[10] = {minion, ambassador, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state; //
	int randomSeed;
	int choice1; //
	int currentPlayer; //
	int handPos; 
	int card; //

	srand(time(0));


	randomSeed = rand();
	
	//for loop for number of tests
	for(int i = 0; i < 10; i++) { 

		//randomize number of players, between 1 and 4
		numPlayers = (rand() % (4 - 1 + 1)) + 1; 

		//initialize game
		initializeGame(numPlayers, kingdomCards, randomSeed, &state); 
	
		//generate random choice between 0 or 1; 
		choice1 = (rand() % (1 - 0 + 1)) + 0; 
	
		//generate a random currentPlayer from 0 to 3; 
		currentPlayer = (rand() % (3 - 0 + 1)) + 0; 
	
		//estate card supply set between 0 and 12 cards
		state.supplyCount[estate] = (rand() % (13 - 0 + 1)) + 0;
	
		//randomize card value between 0 and 26	
		card = rand() % (26 - 0 + 1) + 0;
	
		//randomize card type in hand of currentPlayer
		for(handPos = 0; handPos < 5; handPos++) {
			state.hand[currentPlayer][handPos] = card; 
		}
		
		//set the handCount of the currentPlayer to 5 cards
		state.handCount[currentPlayer] = 5; 
		
		//function call to baronTest 
		baronTest(&state, choice1, currentPlayer);
	
	}
	
	return 0; 	
}

//CASE BARON
//Player can either discard an estate card and win 4 coins OR gain a new estate card
int baronTest(struct gameState *state, int choice1, int currentPlayer) {
	//previous gameState
	struct gameState prevState;

	//create memory from previous gameState
	memcpy(&prevState, state, sizeof(struct gameState));

	//function call to baronRefactor
	baronRefactor(state, choice1, currentPlayer);
	
	prevState.numBuys++;//Increase buys by 1!
	
	if(choice1 == 1) {
		//if the currentPlayer, 0 is holding an estate card
		if(prevState.hand[currentPlayer][0] == estate) {
			prevState.coins += 4;//Add 4 coins to the amount of coins
	    		prevState.handCount[currentPlayer]--;
	    		prevState.discardCount[currentPlayer]++;
		}
		
		//if the currentPlayer is NOT holding an estate card, add an estate card
		else {
				prevState.discardCount[currentPlayer]++;
				prevState.discard[currentPlayer][prevState.discardCount[currentPlayer] - 1] = estate;
				prevState.supplyCount[estate]--;
		}
	}

	//else the currentPlayer is NOT holding an estate card, add an estate card
	else {
			prevState.discardCount[currentPlayer]++;
			prevState.discard[currentPlayer][prevState.discardCount[currentPlayer] - 1] = estate;
			prevState.supplyCount[estate]--;
	}

	return 0; 

}
