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

int tributeTest(struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards);

//RANDOM TEST GENERATOR FROM CASE BARON
int main() {
	//declare variables from initalizeGame function
	int numPlayers;
	int kingdomCards[10] = {minion, ambassador, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state; //
	int randomSeed;
	int currentPlayer; //
	int nextPlayer;
	int handPos; 
	int card; //
	int tributeRevealedCards[2] = {-1, -1};

	srand(time(0));


	randomSeed = rand();
	
	//for loop for number of tests
	for(int i = 0; i < 10; i++) { 
		
		numPlayers = (rand() % (4 - 1 + 1)) + 1; 

		//initialize game
		initializeGame(numPlayers, kingdomCards, randomSeed, &state); 
	
		//generate a random currentPlayer from 0 to 3; 
		currentPlayer = (rand() % (3 - 0 + 1)) + 0; 
	
		//randomize card value between 1 and 5
		card = rand() % (5 - 0 + 1) + 0;
	
		//randomize card type in hand of currentPlayer
		for(handPos = 0; handPos < 5; handPos++) {
			state.hand[currentPlayer][handPos] = card; 
		}
		
		//set the handCount of the currentPlayer to 5 cards
		state.handCount[currentPlayer] = 5; 
		
		//function call to baronTest 
		tributeTest(&state, currentPlayer, nextPlayer, tributeRevealedCards);
	
	}
	
	return 0; 	
}

//CASE MINION
//Player can either discard an estate card and win 4 coins OR gain a new estate card
int tributeTest(struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards) {
	//previous gameState
	struct gameState prevState;

	//create memory from previous gameState
	memcpy(&prevState, state, sizeof(struct gameState));

	int i;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;

	cardEffect(tribute, choice1, choice2, choice3, &prevState, handPos, &bonus);

	if((prevState.discardCount[nextPlayer] + prevState.deckCount[nextPlayer]) <= 1) {
		if(prevState.deckCount[nextPlayer] > 0) {
			tributeRevealedCards[0] = prevState.deck[nextPlayer][prevState.deckCount[nextPlayer]-1];
			prevState.deckCount[nextPlayer]--;
		}

		else if(prevState.discardCount[nextPlayer] > 0) {
			tributeRevealedCards[0] = prevState.discard[nextPlayer][prevState.discardCount[nextPlayer]-1];
			prevState.discardCount[nextPlayer]--;
		}
	}

	else {
		if(prevState.deckCount[nextPlayer] == 0) {
			for(i = 0; i < prevState.discardCount[nextPlayer]; i++) {
				prevState.deck[nextPlayer][i] = prevState.discard[nextPlayer][i];
				prevState.deckCount[nextPlayer]++;
				prevState.discard[nextPlayer][i] = -1;
				prevState.discardCount[nextPlayer]--;
			}
		}

		tributeRevealedCards[0] = prevState.deck[nextPlayer][prevState.deckCount[nextPlayer]-1];
		prevState.deck[nextPlayer][prevState.deckCount[nextPlayer]--] = -1;
		prevState.deckCount[nextPlayer]--;
		tributeRevealedCards[1] = prevState.deck[nextPlayer][prevState.deckCount[nextPlayer]-1];
		prevState.deck[nextPlayer][prevState.deckCount[nextPlayer]--] = -1;
		prevState.deckCount[nextPlayer]--;

	}


	if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one
		prevState.playedCards[prevState.playedCardCount] = tributeRevealedCards[1];
		prevState.playedCardCount++;
		tributeRevealedCards[1] = -1;
    }

    for (i = 0; i <= 2; i++){
		if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
	  				prevState.coins += 2;
		}

		else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
	  			drawCard(currentPlayer, &prevState);
	  			drawCard(currentPlayer, &prevState);
		}

		else{//Action Card
	  			prevState.numActions = prevState.numActions + 2;
		}
    }

      return 0;
}

	
