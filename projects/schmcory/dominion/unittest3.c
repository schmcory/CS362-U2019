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
  
   int choice1;
   int choice2;
   int handPos;
   
   //code pulled from playdom.c
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
   struct gameState state;
   initializeGame(2, k, randomSeed, &state); 
  
   state.card[0][0] = ambassador; 
   
   memset(&state, 0, sizeof(struct gameState));
  
  ambassadorRefactor(struct gameState *state, int choice1, int choice2, int handPos) {
  
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
