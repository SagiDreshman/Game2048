#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"


void printBoard(const int* board, int size,int bestScore,int currentScore) { 
	
	// Print the top border of the board
	for(int dash=0; dash < size * 7 + 1; dash++){
		printf("-");
	}
	printf("\n");
	
	// Print each row of the board
	for(int i=0; i < size; i++) {
		printf("|");
		for(int j=0; j < size; j++) {
			int currentValue = *(board + i * size + j); // Get the value at the current cell
			if(currentValue==0) { 
				printf("      "); // Print empty spaces for a cell with 0
			} else { 
				printf(" %5d", currentValue); //print the value
			}
			printf("|");
		}
		printf("\n");  // End of the row
		
		
		// Print again lines of "-" after row
		for(int dash=0; dash < size * 7 + 1; dash++) { 
			printf("-"); 
		}
		printf("\n");	
	}		 
}
                        
// Set all cells to 0                  
void clearBoard(int* board,int size){ //put 0 (spaces) each cell in the board
	for(int i=0;i<size*size;i++) { 
		*(board+i) =0;
	}
}

// Function to place a random tile (2 or 4) on the board
void initRandomBoard(int* board,int size) { 
	srand((unsigned)time(NULL));
	int randomRow, randomCol;
	do {
		randomRow = rand() % size;  
		randomCol = rand() % size; 
	} while (*(board + randomRow * size + randomCol) != 0);
	 
	// Determine the value to place (70% chance for 2, 30% for 4)
	int randomValue = (rand() % 10 < 7) ? 2 : 4; 

	 // Place the value in the chosen cell
	*(board + randomRow * size + randomCol) = randomValue;
}


int maxScoreSpot(const int* board, int size) { //find the max value in the board
	int maxScore = 0;
	
	 // Iterate through the board to find the highest value
	for(int i = 0; i < size * size; i++) { 
		if(*(board+i) > maxScore) {
			maxScore = *(board + i);
		}
	}
	return maxScore;
}

int isBoardFull(int* board, int size) { 
	for (int i = 0; i < size *size; i++) {
		if (*(board + i) == 0) { // If an empty cell is found
		    return 0; //Board is not full
		}
	}
    	
	return 1; //Board is full
}

int hasValidMoveAvailable(int* board, int size){
	int* pCurrent = board; // Pointer to the current cell
	int* pEnd = board + size * size; // Pointer to the end of the board
	int colCounter=0; // Tracks the current column number
	while (pCurrent < pEnd){
		// Check the cell to the right (same row)
		if(colCounter < size-1 && *pCurrent == *(pCurrent + 1 )){
			return 1; // Found a valid move
		}
		// Check the cell below (same column)
		if(pCurrent + size < pEnd && *pCurrent == *(pCurrent + size)) {
			return 1; // Found a valid move
		}
		pCurrent++; // Move to thw next cell
		colCounter++; // Move to thw next column
		// If reach the end of a row, reset the column counter
		if (colCounter == size){
			colCounter =0;
		}
	}
	return 0; // No valid moves found
}
