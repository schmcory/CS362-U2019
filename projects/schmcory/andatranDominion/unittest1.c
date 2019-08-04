#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>

//assert true function
void asserttrue(int actual, int expected) {

	if (actual, expected) {

		printf("Test Passed!\n");
	}

	else {

		printf("Test Failed!\n");
	}
}

/* BARON CARD UNIT TEST:
*Buys increased by 1
*Player has two choices
    *If the player has an estate card
      *gain a new estate card (choice1 = 0)
      *discard an estate card (boolean) and win 4 coins (choice1 = 1)
*/
int main() {
   int choice1;
   int choice2 = 0;
   int choice3 = 0;
   int handpos = 0;
   int bonus = 0;
   
   int randomSeed = 1000;
   
   struct gameState prevState;
   struct gameState state;
   
   int currentPlayer = whoseTurn(&state); 
   
   int k[10] = { baron, ambassador, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room };

   //counters
   int prevBuys;
   int prevEstateCards;	
   int postEstateCards;	
   int prevDiscardCount;
   int postDiscardCount;
   int prevCoins; 

   // initialize a game state and player cards
   initializeGame(2, k, randomSeed, &state);
   
   int i;  //incrementor
   
/*---------------------- UNIT TEST 1: Number of buys increased by 1 -----------------------------*/
   printf("Test Case 1: Testing whether the number of buys increased by 1\n");

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));

   //for loop allows the test case to initiate for both choices 0 and 1
   for(i = 0; i < 2; i++) {
	   choice1 = i;

      printf("If the player chooses to gain a new estate...")
	
       //sets prevBuys variable equal to the number of buys before the card is played
       prevBuys = prevState.numBuys;

	    //call the cardEffect function with the baron card
	    cardEffect(baron, choice1, choice2, choice3, &prevState, handpos, &bonus);

	    //assert true statements to see if test passed
       assertTrue(previousBuys, prevState.numBuys - 1);
   }
/*-------------------------------------------- END UNIT TEST 1 --------------------------------------------*/
   
/*------------------------------------ UNIT TEST 2: Gains an estate --------------------------------------*/
	printf("Test Case 2: Player chooses to gain an estate \n");

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));
   
   //set choice1 = 0

   //sets the prevEstateCards to 0
   prevEstateCards = 0;
   
	//count the number of estates in the players hand before the card is played
	for (i = 1; i < prevEstateCards.handCount[currentPlayer]; i++) {
      //if the player is holding an estate card
		//set the prevEstateCards variable equal to the estate cards the player is holding
		if (prevState.hand[currentPlayer][i - 1] == estate) {
			prevEstateCards += 1;
		}
	}

   //sets the prevDiscardCount to 0 
	prevDiscardCount = 0;
   
   //count the number of discarded estate cards from the players hand before the card is played
	for (i = 0; i < prevState.discardCount[currentPlayer]; i++) {
		if (prevState.deck[currentPlayer][i] == estate) {
			prevDiscardCount += 1;
		}
	}

	//call the cardEffect function
	cardEffect(baron, choice1, choice2, choice3, &prevState, handpos, &bonus);

	//count the number of estates in the players hand after the card is played
	postEstateCards = 0;
	for (i = 1; i < prevState.handCount[currentPlayer]; i++) {
		if (prevState.hand[currentPlayer][i - 1] == estate) {
			postEstateCards += 1;
		}
	}

   //count the number of discarded estate cards from the players hand after the card is played
	postDiscardCount = 0;
	for (i = 0; i < prevState.discardCount[currentPlayer]; i++) {
		if (prevState.deck[currentPlayer][i] == estate) {
			postDiscardCount += 1;
		}
	}

	//assert true statements to see if test passed
	assertTrue(prevEstateCards, postEstateCards + 1);
	assertTrue(prevState.coins, prevCoins);
	assertTrue(prevDiscardCount, postDiscardCount);
/*-------------------------------------------- END UNIT TEST 2 --------------------------------------------*/
   
/*---------------------- UNIT TEST 3: Estate card discarded and coins gained by 4 --------------------------------------*/
   printf("Test Case 3: Testing whether an estate card was discarded and four coins were gained\n")

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));
   
   //set choice1 = 1
	choice1 = 1;

   //sets the prevEstateCards to 0
   prevEstateCards = 0;
   
	//count the number of estates in the players hand before the card is played
	for (i = 1; i < prevEstateCards.handCount[currentPlayer]; i++) {
      //if the player is holding an estate card
		//set the prevEstateCards variable equal to the estate cards the player is holding
		if (prevState.hand[currentPlayer][i - 1] == estate) {
			prevEstateCards += 1;
		}
	}

   //sets the prevDiscardCount to 0 
	prevDiscardCount = 0;
   
   //count the number of discarded estate cards from the players hand before the card is played
	for (i = 0; i < prevState.discardCount[currentPlayer]; i++) {
		if (prevState.deck[currentPlayer][i] == estate) {
			prevDiscardCount += 1;
		}
	}
   
   //set the prevCoins of to the state coins 
	prevCoins = state.coins;
   
	//call the cardEffect function
	cardEffect(baron, choice1, choice2, choice3, &prevState, handpos, &bonus);

	//count the number of estates in the players hand after the card is played
	postEstateCards = 0;
	for (i = 1; i < prevState.handCount[currentPlayer]; i++) {
		if (prevState.hand[currentPlayer][i - 1] == estate) {
			postEstateCards += 1;
		}
	}

   //count the number of discarded estate cards from the players hand after the card is played
	postDiscardCount = 0;
	for (i = 0; i < prevState.discardCount[currentPlayer]; i++) {
		if (prevState.deck[currentPlayer][i] == estate) {
			postDiscardCount += 1;
		}
	}
   
	//assert true statements to see if test passed
	assertTrue(prevEstateCards, postEstateCards + 1);
	assertTrue(prevState.coins, prevCoins + 4);
	assertTrue(prevDiscardCount, postDiscardCount - 1);
/*-------------------------------------------- END UNIT TEST 3 --------------------------------------------*/

	return 0;
}
   
