#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test Shuffle function
int main(int argc, char **argv){
 struct gameState Game;
 int a, random, player = 0;
 int k[10] = {adventurer, gardens, embargo, village, minion, mine,
              cutpurse, sea_hag, tribute, smithy};
 random = rand() % 10;

 a = initializeGame(2, k, random, &Game);
 assert(a == 0);
 printf("Unittest 3:\n");

 //Invalid testing
 //Bug is -1000 for the deckCount array in struct Game 
 Game.deckCount[player] = -1000;
 a = shuffle(player, &Game);
 assert(a == -1);

//Valid testing   
 Game.deckCount[player] = 5;
 a = shuffle(player, &Game);
 assert(a == 0);
 
 printf("UNIT TEST 3 PASSED\n");
 return 0;
}
