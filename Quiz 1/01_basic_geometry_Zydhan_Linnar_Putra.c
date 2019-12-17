#include <stdio.h>

#define pi 3.14159265359 // we need this to count area of circle

int main() {
	// Variable declaration
	float base;
	float base1;
	float base2;
	float height;
	float side_length;
	float radius;
	
	// Ask base from user
	printf( "Base: " );
	scanf( "%f", &base);
	
	// Ask base1 from user
	printf( "Base 1: " );
	scanf( "%f", &base1);
	
	// Ask base2 from user
	printf( "Base 2: " );
	scanf( "%f", &base2);
	
	// Ask height from user
	printf( "Height: " );
	scanf( "%f", &height);
	
	// Ask side_length from user
	printf( "Length: " );
	scanf( "%f", &side_length);
	
	// Ask radius from user
	printf( "Radius: " );
	scanf( "%f", &radius);
	
	// Print output
	printf( "Area of a Rectangle: %.2f\n", (base*height) );
	printf( "Area of a Square: %.2f\n", (side_length*side_length) );
	printf( "Area of Triangle: %.2f\n", (base*height/2) );
	printf( "Area of Parallelogram: %.2f\n", (base*height) );
	printf( "Area of Trapezoid: %.2f\n", ((base1+base2)*height/2) );
	printf( "Area of Circle: %.2f\n", (pi*radius*radius) );
	
	return 0;
}
