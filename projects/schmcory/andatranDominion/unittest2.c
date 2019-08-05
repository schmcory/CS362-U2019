#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

//assert true function
void assertTrue(int actual, int expected) {

	if (actual == expected) {

		printf("Test Passed!\n");
	}

	else {

		printf("Test Failed!\n");
	}
}


/* MINION CARD UNIT TEST:
* Player has two choices
      *Win 2 coins (choice1) 
      *discard Minion card + 4 other cards (choice2)
          *players with 5+ cards discard hand, draw another 4 cards
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
   
   int currentPlayer = 0;
   int nextPlayer = 1; 
   
   int k[10] = { baron, ambassador, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room };

   //counters
   int prevActions;	
   int postActions;	
   int prevCoins;
   int prevHandCount;
   int prevHandCount2;

   // initialize a game state and player cards
   initializeGame(2, k, randomSeed, &state);
   
   int i;  //incrementor
   
/*---------------------- UNIT TEST 1: Coins increased by 2 -----------------------------*/
   printf("Test Case 1: Testing whether player won two coins\n");

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));
	
     //sets the prevActions variable to the number of actions before the card is played
     prevActions = prevState.numActions; 
     
     //sets the prevCoins variable to the number of coins before the card is played
     prevCoins = prevState.coins;
     
     //sets prevHandCount variable equal to the handCount of the currentPlayer before the card is played 
     prevHandCount = prevState.handCount[currentPlayer];
     
     choice1 = 1;
     choice2 = 0;

	//call the cardEffect function with the baron card
	cardEffect(minion, choice1, choice2, choice3, &prevState, handpos, &bonus);

	//assert true statements to see if test passed
     asserttrue(prevState.numActions, prevActions);
     asserttrue(prevState.coins, prevCoins + 2);
     asserttrue(prevState.handCount[currentPlayer], prevHandCount - 1);
   }
/*-------------------------------------------- END UNIT TEST 1 --------------------------------------------*/
   
/*------------------------------------ UNIT TEST 2: Discards Minion card + 4 other cards, next player (with 5+ cards) draws another 4 cards --------------------------------------*/
	printf("Test Case 2: Testing whether player discards minion card + 4 other cards\n");

     //test whether player 2 has 5 cards
     for(i = 0; i < 5; i++) {
          drawCard(1, &state); 
     }

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));
   
     //sets the prevActions variable to the number of actions before the card is played
     prevActions = prevState.numActions; 
     
     //sets the prevCoins variable to the number of coins before the card is played
     prevCoins = prevState.coins;
     
     //sets prevHandCount variable equal to the handCount of the currentPlayer before the card is played 
     prevHandCount = prevState.handCount[currentPlayer];  

     //sets the postHandCount variable equal to the handCount of the nextPlayer before the card is played
     prevHandCount2 = prevState.handCount[nextPlayer];

     choice1 = 0;
     choice2 = 1;

     //call the cardEffect function with the baron card
	cardEffect(minion, choice1, choice2, choice3, &prevState, handpos, &bonus);
   
	//assert true statements to see is test passed
     asserttrue(prevState.numActions, prevActions);
     asserttrue(prevState.coins, prevCoins);
     asserttrue(prevState.handCount, 4);
     asserttrue(prevState.handCount, 4);
/*-------------------------------------------- END UNIT TEST 2 --------------------------------------------*/

	return 0;
}
