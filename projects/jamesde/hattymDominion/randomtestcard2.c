#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int main (int argc, char** argv) {
	struct gameState Game;
	int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse, 
	             sea_hag, tribute, smithy};
    int numberPlayers = 2;
	int currentPlayer = 0;
	int deckSize, handSize, deckPre, deckPost, handPre, handPost, handPostion, discardPre, discardPost, i, j;
	int passed;
	int handFail = 0;
	int deckFail = 0;
	int discardFail = 0;
	int testResult = 0;
    
	srand(time(NULL));
	printf("********Running Random Test for Smithy Card********\n");
	for(i = 0; i < 10000; i++){
		initializeGame(numberPlayers, k, 1000, &Game);
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize + 1);
		
		Game.deckCount[0] = deckSize - handSize;
		Game.handCount[0] = handSize;
		
		handPostion = Game.hand[currentPlayer][Game.handCount[currentPlayer] - 1];
		
		deckPre = Game.deckCount[0];
		printf("Deck Count Before: %d\n", deckPre);
		handPre = Game.handCount[0];
		printf("Hand Count Before: %d\n", handPre);
		discardPre = Game.playedCardCount;
		printf("Discarded Cards Before: %d\n", discardPre);
		
		//My Refactor function
		//smithyCard(currentPlayer, handPostion, &Game);
		//Classmate refactor function
		smithyEffect(&Game, currentPlayer, handPostion);
		
		deckPost = Game.deckCount[0];
		printf("Deck Count After: %d\n", deckPost);
		handPost = Game.handCount[0];
		printf("Hand Count After: %d\n", handPost);
		discardPost = Game.playedCardCount;
		printf("Discarded Cards After: %d\n", discardPost);
		
		passed = 1;
		
		if(handPost != (handPre + 3)){
			printf("Wrong number of cards were drawn: FAILED!!\n");
			handFail++;
			passed = 0;
		}
		
		if(deckPost != (deckPre - 4)){
			printf("Wrong number of cards were removed from player's deck: FAILED!!\n");
			deckFail++;
			passed = 0;
		}
		
		if(discardPost != (discardPre + 1)){
			printf("Smithy Card was not discarded: FAILED!!\n");
			discardFail++;
			passed = 0;
		}
			
		if(passed == 1){
			printf("Smithy Card Test PASSED!!\n");
			testResult++;
		}
	}
 
 printf("Number of Tests Passed: %d\n", testResult);
 printf("Incorrect amount in Player's deck: %d\n", deckFail);
 printf("Number of Smithy Cards Drawn to Hand Failed: %d\n", handFail);
 printf("Number of Smithy Cards Discarded Failed: %d\n", discardFail);
 
 return 0;
}
