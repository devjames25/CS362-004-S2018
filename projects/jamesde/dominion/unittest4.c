#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test game over
int main(int argc, char** argv){
 struct gameState Game;
 int a, random = 0;
 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,      sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);

//Test for crashes
 assert(a == 0);
 printf("Unit Test 4:\n");

//Test for the state of the game.
 for(int i = 20; i>= 0; i--){
     Game.supplyCount[i] = i;
     a = isGameOver(&Game);
 }
 printf("UNIT TEST 4 PASSED.\n");
 return 0;
}
