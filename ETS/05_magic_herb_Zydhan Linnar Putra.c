#include <stdio.h>

void operation(int n, int n1, int i);
// Declare global array and variable because it is used by 2 function
int number[] = {94,222,221,186,181,208,207,110,187,185,17,212,115,215,100};
int designated[60];
int j=0;

int main() {
	int i;
	// Execute operation from right
	operation(number[14],number[13], 14);
	
	// Printf from latest word in designated[]
	for(i=j-1; i>=0; i--) {
		printf("%c\n", designated[i]);
	}
	
	return 0;
}

void operation(int n0, int n1, int i) {
	int results=0;
	int design=0;
	// if one of the four operations found designated number, store it in designated[]
	if((results=n1+n0)>=65 && (results=n1+n0)<=122) {
		design=1;
		results=n1+n0;
	} else if((results=n1-n0)>=65 && (results=n1-n0)<=122) {
		design=1;
		results=n1-n0;
	} else if((results=(n1*2)-n0)>=65 && (results=(n1*2)-n0)<=122) {
		design=1;
		results=(n1*2)-n0;
	} else if((results=((n1-3)*2)+n0)>=65 && (results=((n1-3)*2)+n0)<=122) {
		design=1;
		results=((n1-3)*2)+n0;
	}
	if(design==1) {
		designated[j]=results;
		j++;
		i--;
		number[i]=results;
		if (i>0) {
			operation(number[i],number[i-1], i);
		}
	} else {
		i--;
		if(i>0) {
			operation(number[i],number[i-1], i);
		}
	}
}
