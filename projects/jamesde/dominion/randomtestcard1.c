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
	int otherPlayer = 1;
	int deckSize, handSize, deckPre, deckPost, handPre, handPost, handPostion, discardPre, discardPost, i, j;
	int testNumAct, passed;
	int handFail = 0;
	int deckFail = 0;
	int handFail2 = 0;
	int deckFail2 = 0;
	int numActionsFail = 0;
	int testResult = 0;
	int deckPre2, handPre2, deckPost2, handPost2, handPostion2;
	
	
	srand(time(NULL));
	printf("********Running Random Test for Council Room Card********\n");
	for(i = 0; i < 10000; i++){
		initializeGame(numberPlayers, k, 1000, &Game);
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize + 1);
		
		Game.deckCount[0] = deckSize - handSize;
		Game.handCount[0] = handSize;
		
		Game.deckCount[1] = deckSize - handSize;
		Game.handCount[1] = handSize;
		
		handPostion = Game.hand[currentPlayer][Game.handCount[currentPlayer] - 1];
		handPostion2 = Game.hand[otherPlayer][Game.handCount[otherPlayer] - 1];
		
		deckPre = Game.deckCount[0];
		printf("Deck Count Before for Player 1: %d\n", deckPre);
		handPre = Game.handCount[0];
		printf("Hand Count Before for Player 1: %d\n", handPre);
		
		deckPre2 = Game.deckCount[1];
		printf("Deck Count Before for Player 2: %d\n", deckPre2);
		handPre2 = Game.handCount[1];
		printf("Hand Count Before for Player 2: %d\n", handPre2);
		
		
                //Refactor function
		council_roomCard(currentPlayer, handPostion, &Game);
		
		deckPost = Game.deckCount[0];
		printf("Deck Count After for Player 1: %d\n", deckPost);
		handPost = Game.handCount[0];
		printf("Hand Count After for Player 1: %d\n", handPost);
		
		deckPost2 = Game.deckCount[1];
		printf("Deck Count Before for Player 2: %d\n", deckPost2);
		handPost2 = Game.handCount[1];
		printf("Hand Count Before for Player 2: %d\n", handPost2);
	
	    passed = 1;
		
		if(handPost != (handPre + 3)){
			printf("Wrong number of cards were drawn: FAILED!!\n");
			handFail++;
			passed = 0;
		}
		
		if(deckPost != (deckPre - 4)){
			printf("Wrong number of cards were removed from player 1's deck: FAILED!!\n");
			deckFail++;
			passed = 0;
		}
		
		
		if(handPost2 != (handPre2 + 3)){
			printf("Wrong number of cards were drawn: FAILED!!\n");
			handFail2++;
			passed = 0;
		}
		
		if(deckPost2 != (deckPre2 - 4)){
			printf("Wrong number of cards were removed from player 2's deck: FAILED!!\n");
			deckFail2++;
			passed = 0;
			
		}
		
			
		if(passed == 1){
			printf("Council Room Card Test PASSED!!\n");
			testResult++;
		}
	
	}
	printf("Number of Tests Passed: %d\n", testResult);
	printf("Incorrect amount in Player 1's deck: %d\n", deckFail);
	printf("Incorrect amount in Player 2's deck: %d\n", deckFail2);
	printf("Number of Council Room Cards Drawn to Player 1's Hand Failed: %d\n", handFail);
	printf("Number of Council Room Cards Drawn to Player 2's Hand Failed: %d\n", handFail2);
	
	return 0;
}
