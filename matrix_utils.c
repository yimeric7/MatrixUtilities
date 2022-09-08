/*
	Name: Eric Yim
	NUID: 08021774
	Date: 3/30/2022
	Description: Generate program that tests several small utility functions 
				 based on dynamic integer matrices
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Declare functions
int** makeMatrix (int n);
void printMatrix (int **A, int n);
bool sumEqual (int **A, int **B, int n);
bool isEqual (int **A, int **B, int n);
int diagonal (int **A, int n);
int** sumMatrix (int **A, int **B, int n);
int** product (int **A, int **B, int n);
int** subtractMatrix (int **A, int **B, int n);
double** inverseMatrix (int **A, int n);
double** matrixDivision (int **A, int **B, int n);

int main (void) {
	int n = 0;
	int choice = 0; 
	bool boolResult = 0; 
	int result = 0; 

	// Prompt user for inputs to create both matrices 
	printf("Please enter a value for the size of the matrix: \n");
	scanf("%d", &n);
	
	printf("Enter values for matrix A: \n");
	int **matrixA = makeMatrix(n);
	printf(" \n");
	
	printf("Matrix A: \n");
	printMatrix(matrixA, n);
	printf(" \n");
	
	printf("Enter values for matrix B: \n");
	int **matrixB = makeMatrix(n);
	printf(" \n");
	
	printf("Matrix B: \n");
	printMatrix(matrixB, n);
	printf(" \n");
	
	// Begin printing menu
	while (1) {
		printf("Enter a number between 1 and 11 to select your\nchoice from the following menu. \n");
		printf(" \n");
		printf("1.  Check Sum of Elements of Matrices A and B\n");
		printf("2.  Check If Matrices A and B are Identical\n");
		printf("3.  Product of Diagonal Elements of Matrix A\n");
		printf("4.  Product of Diagonal Elements of Matrix B\n");
		printf("5.  Sum of Matrices A and B\n");
		printf("6.  Product of Matrices A and B\n");
		printf("7.  Matrix B Subtracted from Matrix A\n");
		printf("8.  Inverse of Matrix A\n");
		printf("9.  Inverse of Matrix B\n");
		printf("10. Matrix A Divided By Matrix B\n");
		printf("11. EXIT\n");
		printf(" \n");
		scanf("%d", &choice);
		printf("Your entered number is:  %d\n", choice);
		
		// Now begin creating outcomes based upon choice entered
		if (choice == 1) {
			boolResult = sumEqual(matrixA, matrixB, n);
			if (boolResult == true) {
				printf("Sum of elements in each matrix is equal\n");
			} else {
				printf("Sum of elements in each matrix is NOT equal\n");
			}
			printf(" \n");
			
		} else if (choice == 2) {
			boolResult = isEqual(matrixA, matrixB, n);
			if (boolResult == true) {
				printf("Matrix A and B are identical\n");
			} else {
				printf("Matrix A and B are NOT identical\n");
			}
			printf(" \n");
			
		} else if (choice == 3) {
			result = diagonal(matrixA, n);
			printf("The product of the diagonal elements of A is: %d\n", result);
			printf(" \n");
			
		} else if (choice == 4) {
			result = diagonal(matrixB, n);
			printf("The product of the diagonal elements of B is: %d\n", result);
			printf(" \n");
		
		} else if (choice == 5) {
			printf("The sum of matrix A and B is: \n");
			int **sum = sumMatrix(matrixA, matrixB, n);
			printMatrix(sum, n);
			printf(" \n");
			
		} else if (choice == 6) {
			printf("The product of matrix A and B is: \n");
			int **productMatrix = product(matrixA, matrixB, n);
			printMatrix(productMatrix, n);
			printf(" \n");
		
		} else if (choice == 7) {
			printf("Matrix A - B is:\n");
			int **subtract = subtractMatrix(matrixA, matrixB, n);
			printMatrix(subtract, n); 
			printf(" \n");
		
		} else if (choice == 8) {
			printf("Inverse of matrix A is: \n");
			inverseMatrix(matrixA, n);
			printf(" \n");
			printf(" \n");
			
		} else if (choice == 9) {
			printf("Inverse of matrix B is: \n");
			inverseMatrix(matrixB, n);
			printf(" \n");
			printf(" \n");
			
		} else if (choice == 10) {
			matrixDivision(matrixA, matrixB, n);
			printf(" \n");
			printf(" \n");
			
		} else if (choice == 11) {
			printf("Exiting...");
			break;
			
		} else {
			printf("Invalid Input");
			printf(" \n");
		}
	}
	
	return 0;
}

// Define functions
int** makeMatrix (int n) {
	int i, j, k;
	
	int **matrix = (int**) malloc(sizeof(int*) * n);
	for (k = 0; k < n; k++) {
		matrix[k] = (int*) malloc(sizeof(int) * n);
	}
		
	if (n > 0) {
		// Scan input numbers into new matrix
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
	
	} else {
		printf("Error: Please enter a valid number");
		exit(1);
	}	
	
	return matrix;
}

void printMatrix (int **A, int n) {
	int i, j;
	
	printf(" \n");
	printf(" \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf(" \n");
}

bool sumEqual (int **A, int **B, int n) {
	int sumA = 0, sumB = 0;
	int i,j,k,l;
	
	// Add up matrix A and store in sum A
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sumA += A[i][j];
		}
	}
	
	// Add up Matrix B and store in sum B
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			sumB += B[k][l];
		}
	}
	
	// If sum of A is equal to sum of B, return true
	if (sumA == sumB) {
		return true;
	} else {
		return false;
	}
}

bool isEqual (int **A, int **B, int n) {
	int i,j;
	
	// Compare matrices for all elements
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
		
			// If there isn't a match, then return false
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	
	return true;
}

// Leads to segmentation fault
int diagonal (int **A, int n) {
	int a,b;
	int diagonalSum = 0;
	
	// Add one to row and column each time you move diagonally
	for (int i = 1; i < n; i++) {
		a = A[i-1][i-1];
		b = A[i][i];
		diagonalSum = a*b;
	}
	
	return diagonalSum;
}

int** sumMatrix (int **A, int **B, int n) {
	int i, j;

	// Create new dynamic Matrix to store sum
	int **AB = (int**) malloc(sizeof(int*) * n);
	for (int k = 0; k < n; k++) {
		AB[k] = (int*) malloc(sizeof(int) * n);
	}
	
	// Add up each element from A & B and store into new Matrix
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			AB[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return AB;
}

int** product (int **A, int **B, int n) {
	int i, j, k;
	
	// Create new dynamic Matrix to store product
	int **AB = (int**) malloc(sizeof(int*) * n);
	for (int l = 0; l < n; l++) {
		AB[l] = (int*) malloc(sizeof(int) * n);
	}
	
	// Multiply each element from A & B using formula and store in new matrix
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	return AB;
}

int** subtractMatrix (int **A, int **B, int n) {
	int i, j;

	// Create new dynamic Matrix to store difference
	int **AB = (int**) malloc(sizeof(int*) * n);
	for (int k = 0; k < n; k++) {
		AB[k] = (int*) malloc(sizeof(int) * n);
	}
	
	// Subtract each element from A & B and store into new Matrix
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			AB[i][j] = A[i][j] - B[i][j];
		}
	}
	
	return AB;
}

double** inverseMatrix (int **A, int n) {
	double a,b,c,d;
	double ad = 0;
	double bc = 0;
	double determinate = 0;
	
	// Create new matrix to store inverse values
	double **inverse = (double**) malloc(sizeof(double*) * n);
	for (int k = 0; k < n; k++) {
		inverse[k] = (double*) malloc(sizeof(double) * n);
	}
	
	// matrix must be 2x2
	if (n != 2) {
		printf("Error: Matrix must be 2x2, returning to menu...\n");
		return 0; 
	} else if (n == 2) {
	
		// Create ad
		for (int i = 1; i < n; i++) {
			a = A[i-1][i-1];
			d = A[i][i];
			ad = a*d;
		}
		
		// Create bc
		for (int j = 1; j < n; j++) {
			b = A[j-1][j];
			c = A[j][j-1];
			bc = b*c;
		}
		
		// Determinate
		determinate = ad - bc;
		if (determinate == 0) {
			printf(" \n");
			printf(" \n");
			printf("Det = 0 so matrix is singular.\n");
			return 0;
		}
		
		// Create new values
		double e = 0, f = 0, g = 0, h = 0;
		e = d/determinate;
		f = -b/determinate;
		g = -c/determinate; 
		h = a/determinate;
		
		// Store new values 
		inverse[0][0] = e;
		inverse[0][1] = f;
		inverse[1][0] = g;
		inverse[1][1] = h;
	
		// Print new matrix with output as double
		int m, o;
		
		printf(" \n");
		printf(" \n");
		for (m = 0; m < n; m++) {
			for (o = 0; o < n; o++) {
				printf("%f ", inverse[m][o]);
			}
			printf("\n");
		}
		
	}
	
	return 0;
}

double** matrixDivision (int **A, int **B, int n) {
	double a,b,c,d;
	double ad = 0;
	double bc = 0;
	double determinate = 0;
	
	// Create new matrix to store inverse values
	double **inverse = (double**) malloc(sizeof(double*) * n);
	for (int k = 0; k < n; k++) {
		inverse[k] = (double*) malloc(sizeof(double) * n);
	}
	
	// Create new matrix to store division values
	double **division = (double**) malloc(sizeof(double*) * n);
	for (int k = 0; k < n; k++) {
		division[k] = (double*) malloc(sizeof(double) * n);
	}
	
	// matrix must be 2x2
	if (n != 2) {
		printf("Error: Matrix must be 2x2, returning to menu...\n");
		return 0; 
	} else if (n == 2) {
	
		// Create ad
		for (int i = 1; i < n; i++) {
			a = B[i-1][i-1];
			d = B[i][i];
			ad = a*d;
		}
		
		// Create bc
		for (int j = 1; j < n; j++) {
			b = B[j-1][j];
			c = B[j][j-1];
			bc = b*c;
		}
		
		// Determinate
		determinate = ad - bc;
		if (determinate == 0) {
			printf("Det = 0 so matrix is singular.\n");
			printf("Matrix was not invertable so division is impossible, returning to menu.\n");
			return 0; 
		}
		
		// Create new values
		double e = 0, f = 0, g = 0, h = 0;
		e = d/determinate;
		f = -b/determinate;
		g = -c/determinate; 
		h = a/determinate;
		
		// Store new values 
		inverse[0][0] = e;
		inverse[0][1] = f;
		inverse[1][0] = g;
		inverse[1][1] = h;
		
		// Multiply A by B inverse using formula & store into division matrix
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				for (int z = 0; z < n; z++) {
					division[x][y] += A[x][z] * inverse[z][y];
				}
			}
		}
	
		// Print new matrix with output as double
		int m, o;
		
		printf("Matrix A divided by B: \n");
		printf(" \n");
		printf(" \n");
		for (m = 0; m < n; m++) {
			for (o = 0; o < n; o++) {
				printf("%f ", division[m][o]);
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
