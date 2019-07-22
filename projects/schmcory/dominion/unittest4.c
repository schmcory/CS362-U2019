#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

/* TRIBUTE CARD UNIT TEST:
    *The currentPlater wins coins for each card the player to the left discards
        *except for curse cards - no coins
    *The player to the left of currentPlayer discards top 2 cards
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
   int k[10] = {tribute, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
   struct gameState state;
     
   initializeGame(2, k, randomSeed, &state);
  
   //initialize player's card to tribute
   state.card[0][0] = tribute;
   
   //code borrowed from player.c
   memset(&state, 0, sizeof(struct gameState)); 
  
   //function call to cardEffect
   cardEffect(ambassador, choice1, choice2, choice3, &state, handPos, &bonus); 
  
   printf("Unit Tests: Tribute");
   printf("Test Case 1: Testing whether two actions occurred"); 
   if(state.numActions == 2) {
       printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }
  
     return 0;  
}
