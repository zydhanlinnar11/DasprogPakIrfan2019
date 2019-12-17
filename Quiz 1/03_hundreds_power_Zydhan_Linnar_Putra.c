#include <stdio.h>

int main() {
	// Variable declaration
	int n;
	int i;

	// Ask value of n from user
	printf( "Input value of n: " );
	scanf( "%d", &n );
	
	/* 	Because limitation of int data type
		We use some variation using for looping */
	
	/* 	If n=0, we print "1" and newline (This because 100^0 is equal to 1)
		If n>0, we only print "1" (without newline) and looping "00" n times
		Because in this quiz, n is an integer and there are no limitation for n, so i assume n can be less than zero
		If n<0, we print "0.0" and then looping "00" until |n| if n<(-2), then print "1" and newline */
	if(n==0) {
		printf("1\n"); //print "1" and newline
	} else if (n>0) {
		printf("1"); // newline will be printed after looping
		// Loop "00" n times
		for(i=1; i<=n; i++) {
			printf("00");
		}
		// Print newline :)
		printf("\n");
	} else {
		// Print 0.0 first and then looping if n<(-2)
		printf("0.0");
		/* 	Looping 00 |n| times
			If n=(-1), we skip looping */
		for(i=-2; i>=n; i--) {
			printf("00");
		}
		// Print 1 and newline after looping
		printf("1\n");
	}
	
	return 0;
}
