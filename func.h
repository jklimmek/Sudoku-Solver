#pragma once

int createMatrix(int*** pTab, int nSize);
void deleteMatrix(int*** pTaba, int nSize);
void printMatrix(int** pTab, int nSize);
void setSudoku(char* file, int*** pTab, int nSize);
int checkNumber(int** pTab, int nSize, int spotX, int spotY, int number);
int solveSudoku(int*** pTab, int nSize);
int findEpmtyField(int** pTab, int nSize, int* x, int* y);
