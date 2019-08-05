#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


//assert true function
void assertTrue(int actual, int expected) {

	if (actual, expected) {

		printf("Test Passed!\n");
	}

	else {

		printf("Test Failed!\n");
	}
}


/* AMABASSADOR CARD UNIT TEST:
* Player has one choice
    *The player can return 2 copies of any card from their hand back to supply
    *All other players gain a copy of the card the player returned
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
   int prevHandCount1;	
   int postHandCount1;
   int prevHandCount2;	
   int postHandCount2;

   // initialize a game state and player cards
   initializeGame(2, k, randomSeed, &state);
   
   int i;  //incrementor
   
/*---------------------- UNIT TEST 1: Returns 2 cards -----------------------------*/
   printf("Test Case 1: Testing whether player returned 2 cards\n");

	//copy the game state
	memcpy(&prevState, &state, sizeof(struct gameState));
	
     //sets the coins to 0
     state.coins = 0; 
  
  prevHandCount1 = prevState.handCount[currentPlayer]; 
  postHandCount1 = state.handCount[currentPlayer];
  prevHandCount2 = prevState.handCount[nextPlayer]; 
  postHandCount3 = state.handCount[nextPlayer];  
  
  //for loop sets hand of both players
  for(int i = 0; i < 2; i++) {
     for(int j = 0; j < 5; j++ {
         if(j == 0) {
               state.hand[i][j] = tribute;  
         }
        
         else if(j == 5 - 1) {
               state.hand[i][j] = ambassador;
         }
        
         else {
               state.hand[i][j] = gold;
         }
     }
  }
         
  state.handCount[nextPlayer] = 5; 
         
  choice1 = 0;
  choice2 = 2;
  handPos = 4;
  state.whoseTurn = currentPlayer;

//call the cardEffect function with the ambassador card
cardEffect(ambassador, choice1, choice2, choice3, &prevState, handpos, &bonus);

	//assert true statements to see if test passed
     asserttrue(postHandCount1, prevHandCount1);
     asserttrue(postHandCount2, prevHandCount2);
     asserttrue(state.discardCount[nextPlayer], prevState.discardCount[nextPlayer]);
   }
/*-------------------------------------------- END UNIT TEST 1 --------------------------------------------*/
   return 0;  
 }
