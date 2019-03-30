#include <memory.h>
#include <cstdlib>
#include <iostream>;
#include "func.h"
#include <time.h>

#define SIZE 9

int main()
{
	int** sudoku = NULL;
	if (!createMatrix(&sudoku, SIZE))
		return 1;

	setSudoku("Data.txt", &sudoku, SIZE);

	printMatrix(sudoku, SIZE);
	printf("\n\n");

	clock_t start;

	start = clock();
	if (solveSudoku(&sudoku, SIZE)) {
		double time = (double)(clock() - start) / CLOCKS_PER_SEC;
		printf("SOLVING TIME: %.3lfs \n\n", time);
		printMatrix(sudoku, SIZE);
		printf("\n\n");
	}
	else printf("NO POSSIBLE SOLUTION\n\n");
	
	deleteMatrix(&sudoku, SIZE);
    return 0;
}

