#include <memory.h>
#include <cstdlib>
#include <iostream>
#include "func.h"

#define EMPTY_CELL 0

int createMatrix(int*** pTab, int nSize) {
	*pTab = (int**)calloc(nSize, sizeof(int*));
	if (!pTab) return 0;
	for (int i = 0; i < nSize; i++) {
		(*pTab)[i] = (int*)calloc(nSize, sizeof(int));
		if (!pTab[i]) return 0;
	}
	return 1;
}


void deleteMatrix(int*** pTab, int nSize){
	for (int i = 0; i < nSize; i++) {
		free((*pTab)[i]);
	}
	free(*pTab);
	*pTab = NULL;
}


void printMatrix(int** pTab, int nSize) {
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			if (j != 0 && j % 3 == 0) printf("  ");
			printf("%d ", pTab[i][j]);
		}
		if ((i+1) % 3 == 0 && i != 0) printf("\n");
		printf("\n");
	}
}

void setSudoku(char* file, int*** pTab, int nSize) {
	FILE* fFile;
	fFile = fopen(file, "r");
	if (!fFile)
		return;

	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++)
			fscanf(fFile, "%d", &(*pTab)[i][j]);
	}
}

int checkNumber(int** pTab, int nSize, int spotX, int spotY, int number) {
	for (int i = 0; i < nSize; i++) 
		if (pTab[spotX][i] == number)
			return 0;

	for (int i = 0; i < nSize; i++)
		if (pTab[i][spotY] == number)
			return 0;

	int indexX = (spotX / 3) * 3;
	int indexY = (spotY / 3) * 3;

	for (int i = indexX; i <= indexX + 2; i++) {
		for (int j = indexY; j <= indexY + 2; j++) {
			if (pTab[i][j] == number)
				return 0;
		}
	}
	return 1;
}

int solveSudoku(int*** pTab, int nSize) {
	int x;
	int y;

	if (!findEpmtyField(*pTab, nSize, &x, &y))
		return 1;

	for (int number = 1; number <= 9; number++) {
		if (checkNumber(*pTab, nSize, x, y, number)){
			(*pTab)[x][y] = number;
			if (solveSudoku(pTab, nSize)) return 1;
			(*pTab)[x][y] = EMPTY_CELL;
		}
	}
	return 0;
}

int findEpmtyField(int** pTab, int nSize, int* x, int* y) {
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			if (pTab[i][j] == EMPTY_CELL) {
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}