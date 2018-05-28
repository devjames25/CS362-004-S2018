#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing end turn function
int main(int argc, char** argv){
 struct gameState Game;
 int a, random = 0;
 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
              sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);
 assert(a == 0);
 printf("Unittest2:\n");

 Game.whoseTurn = 0;
 a = endTurn(&Game);
 assert(a == 0);

 Game.whoseTurn = 1;
 a = endTurn(&Game);
 assert(a == 0);

 printf("UNIT TEST 2 PASSED\n");
 return 0;
}
