#include <stdio.h>

int main() {
	// Variable declaration
	float height;
	float weight;
	int gender;
	
	// Ask height from user
	printf( "Enter height: " );
	scanf( "%f", &height);
	
	// Ask weight from user
	printf( "Enter weight: " );
	scanf( "%f", &weight);
	
	// Ask gender from user
	printf( "Enter gender: " );
	scanf( "%d", &gender);
	
	/*	Counting for ideal weight
		We use 0 for female and 1 for male
		If height<=150 we use 45.5 ideal weight for female and 50 for male
		If height>150 we use the Devine weight formula	*/
	float ideal_weight; // Declare variable first
	
	if(gender==0) {
		ideal_weight=45.5;
		if(height>150) {
			ideal_weight+=(2.3*(height-150)/2.5);
		}
	} else if(gender==1) {
		ideal_weight=50;
		if(height>150) {
			ideal_weight+=(2.3*(height-150)/2.5);
		}
	}
	
	// Print output
	if(weight==ideal_weight) {
		printf( "Ideal\n" );
	} else if(((ideal_weight/weight)<1) && ((ideal_weight/weight)>=0.5)) {
		printf( "Overweight\n" );
	} else if((ideal_weight/weight)<0.5) {
		printf( "Obese\n" );
	} else if(((ideal_weight/weight)>1) && ((ideal_weight/weight)<=2)) {
		printf( "Underweight\n" );
	} else if((ideal_weight/weight)>2) {
		printf( "Anorexic\n" );
	}
	
	return 0;
}
