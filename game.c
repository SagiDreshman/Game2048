#include <stdio.h>
#include <ctype.h>
#include "game.h"
#include "board.h"
#include "Steps.h"

void showGameRules() {
	printf("\nPlease choose one of the following options:\n");
	printf("N/n - New Game\n");
	printf("R/r - Move Right\n");
	printf("L/l - Move Left\n");
	printf("U/u - Move Up\n");
	printf("D/d - Move Down\n");
	printf("E/e - Exit\n\n");
}

int isStartTheGame(char moveChoice,int* isStart) { 
	while(1){
		if (moveChoice == 'n'){ // Start the game
			*isStart = 1;
			return 1;
		}
		
		if (moveChoice == 'e'){ // Exit the game
			*isStart = 0;
			return 0;
		}
		
		// One of the menu options - input valid but game not started 
	        if (moveChoice == 'r' || moveChoice == 'l' || moveChoice == 'u' || moveChoice == 'd') { 
			printf("\nNeed to start game first\n"); 
			
		} else { //Invalid input
			printf("\nWorng option\n"); 
		}
		
		// Show menu and request new input
		showGameRules();
		getchar();
		scanf(" %c",&moveChoice);
		moveChoice = tolower(moveChoice);
	}	
}

void playGame(int* board, int size, int scoreToWin) {
	int isStart = 0, bestScore = 0, currentScore = 0;
	char moveChoice = '\0';
	int isCanMove;
	int isFinish = 0;
	
	while (moveChoice != 'e') {
		if (isFinish==0) {
			printBoard(board, size, bestScore, currentScore);
		}
		isFinish = 0;
		showGameRules();
		scanf(" %c", &moveChoice);
		moveChoice = tolower(moveChoice); //To treat both lowercase and uppercase letters
		if (isStart == 0) { //The game not started yet
		    	int result = isStartTheGame(moveChoice, &isStart); 
			
			if (result == 0){
				break;
			}
			
			if (isStart == 1) { //The game has started 
				newGame(board, size, &bestScore, &currentScore, scoreToWin);
				continue; 
			}
		
			continue;	   
		}


		switch (moveChoice) {
		    case 'n':
			newGame(board, size, &bestScore, &currentScore, scoreToWin);
			break;
		    case 'r':
			isCanMove = moveRight(board, size, &bestScore, &currentScore);
			break;
		    case 'l':
			isCanMove = moveLeft(board, size, &bestScore, &currentScore);
			break;
		    case 'u':
			isCanMove = moveUp(board, size, &bestScore, &currentScore);
			break;
		    case 'd':
			isCanMove = moveDown(board, size, &bestScore, &currentScore);
			break;
		    case 'e':
			printf("Ending previous game - your score: %d best score: %d\n",currentScore, bestScore);
			printf("Bye bye!\n");
			break;
		    default:
		    	isCanMove = 0; 
			printf("\nWorng option\n");
			break;
		}
		// If no movement occurred, print a message
		if(isCanMove==0 && (moveChoice =='r' || moveChoice == 'l' || moveChoice == 'u' || moveChoice == 'd')){
			printf("\nNothing to move in this direction, choose another option\n");
		}
		
		if(moveChoice!='n' && isCanMove == 1) {
			//random 2 or 4 in the board
			initRandomBoard(board,size);
			printf("Score %d Best %d\n",currentScore,bestScore);
		}
		
	
		isFinish = endGame(board, size, &bestScore, &currentScore, scoreToWin);
		if (isFinish==1) {
		    isStart = 0; // reset the game mood
		}
		
		
	}

    clearBoard(board, size);
}





		
		
	
	
	
	

