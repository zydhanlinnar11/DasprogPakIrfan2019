#include <stdio.h>

int main() {
	int matrix[3][3];
	int i, j;
	
	// Ask the input from user
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// I'm using cofactor expansion method to count determinant
	int det =	(matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1])))
				-(matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0])))
				+(matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0])));
	
	// Print out the determinant and invertibility of matrix
	printf("Determinant of the matrix = %d\n%s.\n", det, (det==0) ? "The matrix isn't invertible" : "The matrix is invertible");
	
	return 0;
}
