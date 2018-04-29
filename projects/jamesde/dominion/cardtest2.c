#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing smithy card 
int main(int argc, char** argv){
 struct gameState Game;
 int a, random = 0;
 int k[10] = {adventurer, gardens, embargo, village, minion, mine,
              cutpurse, sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);
 assert(a == 0);
 printf("Cardtest 2:\n");

 //Invalid test but contains no bugs
 int card = 4;
 int choice1, choice2, choice3, bonus = 0;
 int handPos = 4;
 a = cardEffect(card, choice1, choice2, choice3, &Game, handPos, bonus);
 assert(a == -1); 
 
 //Valid test but contains bugs in the refactored smithy function
 a = smithyCard(1, handPos, &Game);
 assert(a == 0);

 printf("CARD TEST 2 PASSED\n");

 return 0;
}
