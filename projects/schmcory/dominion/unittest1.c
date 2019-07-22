#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>


/* BARON CARD UNIT TEST:
* Player has two choices
    *If the player has an estate card
      *gain a new estate card
      *discard an estate card (boolean) and win 4 coins
*/


int main () {   
   int choice1 = 1;
   int randomSeed = 1000;
   
   //code pulled from playdom.c
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
   struct gameState state;
   initializeGame(2, k, time, &state); 
   
   //initialize player 1's first card to baron
   state.card[0][0] = baron; 

   //code borrowed from player.c
   memset(&state, 0, sizeof(struct gameState));
   
   printf("Unit Tests: Baron");
   
   /* UNIT TEST 1: Were the number of buys increased by 1" */
   printf("Test Case 1: Testing whether the number of buys increased by 1");
   
   baronRefactor(&state, choice1); 
   
   if(state.numBuys == 1) {
         printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }
   
   /*UNIT TEST 2: Was an estate card discarded? */
   printf("Test Case 2: Testing whether an estate card was discarded");
   if(state.card_not_discarded == 1) {
         printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }
   
   /* UNIT TEST 3: Are 4 coins earned when player discards estate card? */
   printf("Test Case 3: Testing whether 4 coins have been earned after discarding an estate");
   if(state.coins == 4) {
      printf("Test passed.\n");  
   }
   
   else {
      printf("Test failed.\n");
   }
      
}
