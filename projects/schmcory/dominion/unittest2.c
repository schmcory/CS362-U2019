#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


/* MINION CARD UNIT TEST:
* Player has two choices
      *Win 2 coins
      *discard Minion card + 4 other cards
          *players with 5+ cards discard hand, draw another 4 cards
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
     
   //initialize player's card to minion
   state.card[0][0] = minion;
     
   //function call to cardEffect   
   cardEffect(minion, choice1, choice2, choice3, &state, handPos, &bonus); 
   
   //code borrowed from player.c
   memset(&state, 0, sizeof(struct gameState)); 
     
   printf("Unit Tests: Minion");
   /* UNIT TEST 1: Were the number of coins increased by 2?" */
   printf("Test Case 1: Testing whether 2 coins were earned");
   if(state.coins == 2) {
       printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }
     
   /* UNIT TEST 2: Did the player discard the minion card?" */   
   printf("Test Case 2: Testing whether the player discarded the minion card"); 
      if(state.discardCount[0] == 1) {
       printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   }

   /* UNIT TEST 3: Did the player discard 4 other cards?" */ 
   printf("Test Case 3: Testing whether player1 discarded 5 total cards"); 
   if(state.discardCount == 5) {
          printf("Test passed.\n");
   }
   
   else {
      printf("Test failed.\n");
   } 
   
     return 0;  
}
