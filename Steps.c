#include <stdio.h>
#include "Steps.h"
#include "board.h"
void newGame(int* board,int size,int* bestScore,int* currentScore, int scoreToWin){
	printf("----------- STARTING A GAME -----------\n");
	printf("      Highest tile for a win %d\n",scoreToWin );
	printf("---------------------------------------\n\n");
	clearBoard(board,size);
	initRandomBoard(board, size); // Add the first random tile
	initRandomBoard(board, size); // Add the second random tile
	*currentScore=0;
	printf("Score %d Best %d\n", *currentScore, *bestScore);
	
}

int moveUp(int* board,int size,int* bestScore,int* currentScore) {
	int tempValue,currentValue;
	int* pBoard;
	int isCanMoveUp=0; // Flag to check if any movement or merge occurred
	// Loop through each column
	for(int i=0; i<size ;i++){
		int doMergeNumber = 0; // Ensure only one merge per column per turn
		pBoard = board + i; // Start at the bottom of the current column
		 // Traverse rows in the current column
		while(pBoard + size < board + (size * size)){
			currentValue = *pBoard; // Get the current cell value
			tempValue = *(pBoard + size); // Get the value of the cell below
			 // If the current cell is empty and the cell below has a value
			if (currentValue == 0 && tempValue != 0) {
				*pBoard = tempValue;  // Move value up
				*(pBoard + size) = 0; // Clear the original cell (below)
				pBoard = board + i;   // Reset pointer to start of column
				isCanMoveUp = 1;      // Movement occurred
				
			} else {  
				// If two cells have equal values and no merge happened yet
				if (currentValue == tempValue && doMergeNumber==0 && currentValue != 0) { 
					currentValue *= 2;       // Merge values
					*pBoard = currentValue; // Update the cell
					*(pBoard + size) = 0;  // Clear the merged cell (below)
					doMergeNumber = 1;    // Mark merge as done
					isCanMoveUp = 1;     // Movement occurred
					*currentScore += currentValue; //Add the currentValue to the total game score
					if (*currentScore >= *bestScore){
						*bestScore = *currentScore; // Updates the best score if the condition is met 
					}
				}
				pBoard += size; // Move to the next cell in the column
			}
		}
	}
	 return isCanMoveUp;
 }

int moveDown(int* board,int size,int* bestScore,int* currentScore) {
	int tempValue,currentValue;
	int* pBoard;
	int isCanMoveDown=0; // Flag to check if any movement or merge occurred
	// Loop through each column
	for(int i=0; i<size ;i++) {
		int doMergeNumber=0; // Ensure only one merge per column per turn
		pBoard = board + (size * (size -1)) + i; // Start at the top of the current column
		
		  // Traverse rows in the current column
		while(pBoard- size >= board) {
			currentValue = *pBoard;       // Get the current cell value
			tempValue = *(pBoard - size); // Get the value of the cell above
			// If the current cell is empty and the cell above has a value
			if (currentValue == 0 && tempValue != 0) {
				*pBoard = tempValue;     // Move value down
				*(pBoard - size) = 0;    // Clear the original cell (above)
				pBoard = board + (size * (size - 1)) + i; // Reset pointer to start of column
				isCanMoveDown = 1;       // Movement occurred
			} else {
				// If two cells have equal values and no merge happened yet
				if (currentValue == tempValue && doMergeNumber==0 && currentValue != 0) { 
					 currentValue *= 2;  // Merge values
					*pBoard = currentValue; // Update the cell
					*(pBoard - size) = 0;   // Clear the merged cell (above)
					doMergeNumber = 1;      // Mark merge as done
					isCanMoveDown = 1;      // Movement occurred
					*currentScore += currentValue; //Add the currentValue to the total game score
					if (*currentScore >= *bestScore){
						*bestScore = *currentScore; // Updates the best score if the condition is met 
					}
				}
				pBoard -= size; // Move to the next cell in the column
			}
		}
	}
	 return isCanMoveDown;
}

int moveLeft(int* board,int size,int* bestScore,int* currentScore) {
	int tempValue,currentValue;
	int* pBoard;
	int isCanMoveLeft =0; // Flag to check if any movement or merge occurred
	 // Loop through each row
	for(int i=0; i<size ;i++) {
		int doMergeNumber = 0; // Ensure only one merge per row per turn
		pBoard = board + (i * size); // Start at the leftmost cell of the current row

		// Traverse columns in the current row
		while(pBoard + 1 < board + (i * size) +size) {
			currentValue = *pBoard;      // Get the current cell value
			tempValue = *(pBoard + 1);   // Get the value of the next cell
			
			// If the current cell is empty and the next cell has a value
			if (currentValue == 0 && tempValue != 0) {
				*pBoard = tempValue;     // Move value left
				*(pBoard + 1) = 0;       // Clear the original cell (right)
				pBoard = board + (i * size); // Reset pointer to start of row
				isCanMoveLeft = 1;       // Movement occurred
			} else {
				 // If two cells have equal values and no merge happened yet
				if (currentValue == tempValue && doMergeNumber==0 && currentValue != 0) { 
					currentValue *= 2;  // Merge values
					*pBoard = currentValue; // Update the cell
					*(pBoard + 1) = 0;      // Clear the merged cell (right)
					doMergeNumber = 1;      // Mark merge as done
					isCanMoveLeft = 1;      // Movement occurred
					*currentScore += currentValue; //Add the currentValue to the total game score
					if (*currentScore >= *bestScore){
						*bestScore = *currentScore; // Updates the best score if the condition is met 
					}
				}
				pBoard++; // Move to the next cell in the row
			}
		}
	}
	 return isCanMoveLeft;
}

int moveRight(int* board,int size,int* bestScore,int* currentScore) {
	int tempValue,currentValue;
	int* pBoard;
	int isCanMoveRight=0; // Flag to check if any movement or merge occurred
	// Loop through each row
	for(int i=0; i<size ;i++) {
		int doMergeNumber = 0; // Ensure only one merge per row per turn
		pBoard = board + size * (i + 1) - 1; // Start at the rightmost cell of the current row
		 // Traverse columns in the current row
		while(pBoard > board + (i * size)) {
			currentValue = *pBoard;       // Get the current cell value
			tempValue = *(pBoard - 1);    // Get the value of the next cell
			// If the current cell is empty and the next cell has a value
			if (currentValue == 0 && tempValue != 0) {
				*pBoard = tempValue;     // Move value right
				*(pBoard - 1) = 0;       // Clear the original cell (left)
				pBoard = board + size * (i + 1) - 1; // Reset pointer to start of row
				isCanMoveRight = 1;      // Movement occurred
			} else {
				// If two cells have equal values and no merge happened yet
				if (currentValue == tempValue && doMergeNumber==0 && currentValue != 0) { 
					 currentValue *= 2;  // Merge values
					*pBoard = currentValue; // Update the cell
					*(pBoard - 1) = 0;      // Clear the merged cell (left)
					doMergeNumber = 1;      // Mark merge as done
					isCanMoveRight = 1;     // Movement occurred
					*currentScore += currentValue; //Add the currentValue to the total game score
					if (*currentScore >= *bestScore){
						*bestScore = *currentScore; // Updates the best score if the condition is met 
					}
				}
				pBoard--;  // Move to the next cell in the row
			}
		}
		
	}
	return isCanMoveRight;
}


int endGame(int* board,int size,int* bestScore,int* currentScore,int scoreToWin) {
	
	// Check if the winning score has been reached
	int maxScore = maxScoreSpot(board, size);
	if(maxScore == scoreToWin) {
		printBoard(board, size, *bestScore, *currentScore);
		printf("\nYou won %d! - Ending Game\n",scoreToWin);
		clearBoard(board,size);
		*currentScore =0;

		return 1;
	}
	
	// Check if the board is full and no moves are possible
	if(isBoardFull(board, size) && hasValidMoveAvailable(board,size)==0) {	
		printBoard(board, size, *bestScore, *currentScore);
		printf("\nGame Over your score is %d\n",*currentScore);
		clearBoard(board,size);
		*currentScore=0;
		
		return 1;	
	} 

	return 0; // Game is not over yet	
}


