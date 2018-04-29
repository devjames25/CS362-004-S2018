#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing adventure card
int main (int argc, char** argv) {
 struct gameState Game;
 int a, z, random = 0;
 int temphand[MAX_HAND];
 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);
 assert(a == 0);
 printf("Cardtest 1:\n");

 //Invalid testing 
 a = cardEffect(6, 0, 0, 0, &Game, 4, 0);
 assert(a == -1);

 //Valid testign
 a = adventurerCard(1, temphand, 0, &Game);
 assert(a == 0);

 printf("CARD TEST 1 PASSED\n");
 return 0;
}
