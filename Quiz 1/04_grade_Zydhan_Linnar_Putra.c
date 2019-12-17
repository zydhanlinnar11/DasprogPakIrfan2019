#include <stdio.h>

int main() {
	// Variable declaration
	float grade;
	
	// Ask grade from user
	printf( "Input grade: " );
	scanf("%f", &grade);
	
	// Print output
	if ( (grade>=86) && (grade<=100) ) {
		printf( "A\n" );
		printf( "It's 4.0 of 4.0 Scale Grade\n" );
	} else if ( (grade>=76) && (grade<86) ) {
		printf( "AB\n" );
		printf( "It's 3.5 of 4.0 Scale Grade\n" );
	} else if ( (grade>=66) && (grade<76) ) {
		printf( "B\n" );
		printf( "It's 3.0 of 4.0 Scale Grade\n" );
	} else if ( (grade>=61) && (grade<66) ) {
		printf( "BC\n" );
		printf( "It's 2.5 of 4.0 Scale Grade\n" );
	} else if ( (grade>=56) && (grade<61) ) {
		printf( "C\n" );
		printf( "It's 2.0 of 4.0 Scale Grade\n" );
	} else if ( (grade>=41) && (grade<56) ) {
		printf( "D\n" );
		printf( "It's 1.0 of 4.0 Scale Grade\n" );
	} else if ( (grade>=0) && (grade<41) ) {
		printf( "E\n" );
		printf( "It's 0.0 of 4.0 Scale Grade\n" );
	} else {
		printf( "Sorry, your input is out of range, please restart the program.\n" );
	}
	
	return 0;
}
