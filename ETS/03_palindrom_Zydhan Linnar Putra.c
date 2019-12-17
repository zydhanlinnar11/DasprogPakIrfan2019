#include <stdio.h>
#include <string.h>

int main() {
	// I assume the maximum length of string is 1000 because there is no constraint.
	char word[1000],a[1000];
	
	// I use gets instead of scanf because scanf terminated when it found space
    gets(word);
    
    // Copy word to a
    strcpy(a, word);
	
	// Using XOR operation to reverse a
    char *p1, *p2;
	for (p1 = a, p2 = a + strlen(a) - 1; p2 > p1; p1++, p2--) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	
	// Compare a and word after a reversed, if same, so it is palindrom.
	printf("%s\n", (strcmp(a,word)==0) ? "It is a palindrom" : "It is not a palindrom");

    return 0;
}
