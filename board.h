#ifndef __BOARD_H__
#define __BOARD_H__
void printBoard(const int* board, int size,int bestScore,int currentScore );
void clearBoard(int* board,int size);
void initRandomBoard(int* board,int size);
int maxScoreSpot(const int* board, int size);
int isBoardFull(int* board, int size);
int hasValidMoveAvailable(int* board, int size);
#endif
