#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


/* AMABASSADOR CARD UNIT TEST:
* Player has one choice
    *The player can return 2 copies of any card from their hand back to supply
    *All other players gain a copy of the card the player returned
*/

int main() {
   int randomSeed = 1000;
  
   //initialize variables from cardEffect function
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0
   int handPos = 0;
   int bonus = 0; 
   
   //code pulled from playdom.c
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
   struct gameState state;
   initializeGame(2, k, randomSeed, &state); 
  
   state.card[0][0] = ambassador; 

   //code pulled from player.c
   memset(&state, 0, sizeof(struct gameState));
  
   cardEffect(ambassador, choice1, choice2, choice3, &state, handPos, &bonus); 
  
   printf("Unit Tests: Ambassador");
  /* UNIT TEST 1: " */
   printf("Test Case 1: Testing whether the player discarded the two cards"); 
      if(state.discardCount[0] == 2) {
       printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }
  
}
