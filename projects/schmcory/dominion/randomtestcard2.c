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

int minionTest(struct gameState *state, int handPos, int choice1, int choice2, int currentPlayer); 

//RANDOM TEST GENERATOR FROM CASE BARON
int main() {
	//declare variables from initalizeGame function
	int numPlayers;
	int kingdomCards[10] = {minion, ambassador, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state; //
	int randomSeed;
	int choice1; //
	int choice2;
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
	
		//generate random choice1 between 0 and 5; 
		choice1 = (rand() % (5 - 0 + 1)) + 0; 
		
		//generate random choice2 between 0 and 5
		choice2 = (rand() % (5 - 0 + 1)) + 0; 
	
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
		minionTest(&state, handPos, choice1, choice2, currentPlayer);
	
	}
	
	return 0; 	
}

//CASE MINION
//Player can either discard an estate card and win 4 coins OR gain a new estate card
int minionTest(struct gameState *state, int handPos, int choice1, int choice2, int currentPlayer) {
	//previous gameState
	struct gameState prevState;

	//create memory from previous gameState
	memcpy(&prevState, state, sizeof(struct gameState));

	//function call to baronRefactor
	minionRefactor(state, handPos, choice1, choice2, currentPlayer);

	int i;
	int j;
	
	//+1 action
      	prevState.numActions++;
	
	if(choice1) {
		//
		prevState.coins += 2; 

	}
		
	//else the currentPlayer is NOT holding an estate card, add an estate card
	else if(choice2) {
		while(prevState.handCount[currentPlayer] > 0) {
	      		prevState.handCount[currentPlayer]--;
	  	}
		
	  	//draw 4
	  	for (i = 0; i < 4; i++) {
	      		drawCard(currentPlayer, &prevState);
	    	}

	  //other players discard hand and redraw if hand size > 4
	  for (i = 0; i < prevState.numPlayers; i++)
	    {
          /*Bug 6: changed != to ==, if iterrator = currentPlayer, doesn't ever each other players */
	      if (i == currentPlayer)
		{
		  if (prevState.handCount[i] > 4 )
		    {
		      //discard hand
		      while(prevState.handCount[i] > 0 )
			{
			  discardCard(handPos, i, &prevState, 0);
			}

		      //draw 4
		      for (j = 0; j < 4; j++)
			{
			  drawCard(i, &prevState);
			}
		    }
		}
	    }

	}
      return 0;
}
