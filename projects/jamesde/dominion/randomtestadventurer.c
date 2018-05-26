#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
	struct gameState Game;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	             sea_hag, tribute, smithy};
    int numberPlayers = 2;
	int currentPlayer = 0;
	int deckSize, handSize, a, b, c, d, x, randomCard, randomK, coinPre, coinPost, discardCopper, discardSilver, discardGold;
	int passed = 0;
	int drawFail = 0;
	int discardFail = 0;
	int testPassed = 0;
	int temphand[MAX_HAND];
	int z = 0;
	
	srand(time(NULL));
	
	//Choose 10000 since it takes about a minute to run
	for(a = 0; a < 10000; a++){
		initializeGame(numberPlayers, k, 1000, &Game);
		coinPre = 0;
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize + 1);
		
		Game.deckCount[0] = deckSize - handSize;
		Game.handCount[0] = handSize;
		
		for(b = 0; b < numberPlayers; b++){
			for(c = 0; c < Game.deckCount[b]; c++){
				randomCard = rand() % 51;
				randomK = rand() % 10;
				if(randomCard == 1){
					Game.deck[b][c] = copper;
				}
				else if(randomCard == 2){
					Game.deck[b][c] = silver;
				}
				else if(randomCard == 3){
					Game.deck[b][c] = gold;
				}
				else{
					Game.deck[b][c] = k[randomK];
				}
			}
		}
		
		for(d = 0; d < Game.handCount[currentPlayer]; d++){
			if(Game.hand[currentPlayer][d] == copper || Game.hand[currentPlayer][d] == silver || Game.hand[currentPlayer][d] == gold){
			coinPre++;
		}
		
	}
	
	printf("Treasure Card Count before: %d\n", coinPre);
	printf("Discard Count before: %d\n", Game.discardCount[currentPlayer]);

	//Refactor function 
	adventurerCard(currentPlayer, temphand, z, &Game);
    
	coinPost = 0;
	
	for(d = 0; d < Game.handCount[currentPlayer]; d++){
			if(Game.hand[currentPlayer][d] == copper || Game.hand[currentPlayer][d] == silver || Game.hand[currentPlayer][d] == gold){
			coinPost++;
		}
	}
	
	printf("Treasure Card Count after: %d\n", coinPost);
	printf("Discard Count after: %d\n", Game.discardCount[currentPlayer]);
	
    discardCopper = 0;
    discardSilver = 0;
    discardGold = 0;
    for(x = 0; x < Game.discardCount[currentPlayer]; x++){
            if(Game.discard[currentPlayer][x] == copper) {
                discardCopper++;
            } else if(Game.discard[currentPlayer][x] == silver) {
                discardSilver++;
            } else if(Game.discard[currentPlayer][x] == gold) {
                discardGold++;
            }
    }
	int passed = 1;
	
	if(coinPost > coinPre + 2){
		printf("Too many cards were drawn: FAILED!!\n");
		drawFail++;
		passed = 0;
	}
	
	if(coinPost < coinPre){
		printf("Too few cards were drawn: FAILED!!\n");
		drawFail++;
		passed = 0;
	}
	
	if(discardCopper != 0){
            printf("Copper was discarded: FAILED\n");
            discardFail++;
            passed = 0;
    }

    if(discardSilver != 0){
            printf("Silver was discarded: FAILED\n");
            discardFail++;
            passed = 0;
    }

    if(discardGold != 0){
            printf("Gold was discarded: FAILED\n");
            discardFail++;
            passed = 0;
    }

	if(passed == 1){
		printf("All Tests PASSED\n");
		testPassed++;
	}
	
	}
	printf("Number of Tests Passed: %d\n", testPassed);
	printf("Number of Treasure Cards Drawn To Player's hand Failed: %d\n", drawFail);
	printf("Number of Adventure Cards Discareded Fails: %d\n", discardFail);
	
	return 0;
}
