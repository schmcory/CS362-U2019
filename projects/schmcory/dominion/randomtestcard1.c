//randomtestcard1.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int baronRefactor(struct gameState *state, int choice1); 

//RANDOM TEST GENERATOR FROM CASE BARON
int main() {
	//declare variables from initalizeGame function
	int numPlayers;
	int kingdomCards[10];
	int randomSeed;
	struct gameState state;
	int choice1; 
	
	int card_not_discarded = 1; //Flag for discard set!
	
	while(card_not_discarded) {
		//randomly set number of players 
		numPlayers = floor(Random() * MAX_PLAYERS + 1); 
	
		/*if the numPlayers is less than 2 
		if(numPlayers < 2) {
			//if the numPlayers = 1
			if(numPlayers == 1) {
		    		//add at least 1 players
		    		numPlayers += 1; 
			}
		
		//else if the numPlayers = 0
			else if(numPlayers == 0) {
				//add at least 2 players
				numPlayers += 2; 
			}
		}
		*/
	
		//seed time
		srand(time(NULL));
	
		//initalize randomSeed equal to a random number
		randomSeed = rand(); 
	
		//initialize game
		initializeGame(numPlayers, kingdomCards, randomSeed, &state); 
	
		//generate random choice between 0 and 1; 
		choice1 = (int) Random() % 1;  
		
		if(choice1 == 0) {
			baronRefactor(&state, choice1);	
		}
			       
		else {
		      baronRefactor(&state, choice1); 
		}
   }
	
	
}

//CASE BARON
int baronRefactor(struct gameState *state, int choice1) {
      int currentPlayer = whoseTurn(state); //declare currentPlayer variable from cardEffect
      state->numBuys++;//Increase buys by 1!
      if (choice1 > 0){//Boolean true or going to discard an estate
	int p = 0;//Iterator for hand!

	int card_not_discarded = 1;//Flag for discard set!
	while(card_not_discarded){
	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
	    state->coins += 4;//Add 4 coins to the amount of coins
	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
	    state->discardCount[currentPlayer]++;
	    for (;p < state->handCount[currentPlayer]; p++){
	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
	    }
	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
	    state->handCount[currentPlayer]--;
	    card_not_discarded = 0;//Exit the loop
	  }
	  else if (p > state->handCount[currentPlayer]){
	    if(DEBUG) {
	      printf("No estate cards in your hand, invalid choice\n");
	      printf("Must gain an estate if there are any\n");
	    }
	    if (supplyCount(estate, state) > 0){
	      gainCard(estate, state, 0, currentPlayer);
	      state->supplyCount[estate]--;//Decrement estates
	      if (supplyCount(estate, state) == 0){
		isGameOver(state);
	      }
	    }
	    card_not_discarded = 0;//Exit the loop
	  }
    
	  else{
	    p++;//Next card
	  }
	}
      }

      else{
	if (supplyCount(estate, state) > 0){
	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
	  state->supplyCount[estate]--;//Decrement Estates
	  if (supplyCount(estate, state) == 0){
	    isGameOver(state);
	  }
	}
      }

      return 0;
}
