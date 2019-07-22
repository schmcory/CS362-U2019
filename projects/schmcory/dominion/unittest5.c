#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


/* MINE CARD UNIT TEST:
    *The currentPlater must trash treasure cards
        *Trash Copper for Silver, trash Silver for Gold
*/

int main() {
   //initialize variables from cardEffect function
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0
   int handPos = 0;
   int bonus = 0;
  
   int randomSeed = 1000;
   
   //code pulled from playdom.c
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
   struct gameState state;
  
   initializeGame(2, k, randomSeed, &state);
  
   //code borrowed from player.c
   memset(&state, 0, sizeof(struct gameState)); 
   
   //function call to cardEffect
   cardEffect(mine, choice1, choice2, choice3, &state, handPos, &bonus); 
  
   printf("Unit Tests: Mine");
   printf("Test Case 1: Testing whether a card was discarded");
   if(state.discardCount[0] == 1) {
       printf("Test passed.\n");
   }
  
   else {
      printf("Test failed.\n");
   }
   
     return 0;  
  
}
