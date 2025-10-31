#ifndef __STEPS_H__
#define __STEPS_H__
void newGame(int* board,int size,int* bestScore,int* currentScore, int scoreToWin);
int moveUp(int* board,int size,int* bestScore,int* currentScore);
int moveDown(int* board,int size,int* bestScore,int* currentScore);
int moveLeft(int* board,int size,int* bestScore,int* currentScore);
int moveRight(int* board,int size,int* bestScore,int* currentScore);
int endGame(int* board,int size,int* bestScore,int* currentScore,int scoreToWin);

#endif
