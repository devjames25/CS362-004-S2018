#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test buy Card function 
int main(int argc, char** argv){
 struct gameState Game;
 int a, random = 0;
 int k[10] = {adventurer, gardens, embargo, village, minion, mine, 
              cutpurse,sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);
 assert(a == 0);
 printf("Unittest 1:\n");

 Game.coins = 8;
 Game.numBuys = 2;

//Invalid test
//Bug is -2 for the supplyPos parameter
 a = buyCard(-2, &Game);
 assert(a == -1);

//Valid test
 a = buyCard(2, &Game);
 assert(a == 0);

 printf("UNIT TEST 1 PASSED\n");
 return 0;
}
