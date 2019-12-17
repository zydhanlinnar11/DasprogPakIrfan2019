#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

void findandPrintIndexAnagram(char *, char *);

int main() {
    char string[1001], pattern[1001];
    cout<<"String: ";
    cin>>string;
    cout<<"Pattern: ";
    cin>>pattern;
    findandPrintIndexAnagram(string, pattern);

    return 0;
}

void findandPrintIndexAnagram(char string[], char pattern[]) {
    unsigned patternLength = strlen(pattern);
    unsigned stringLength = strlen(string);
    unsigned count = 0;
    for(unsigned i=0; i<=stringLength-patternLength; i++) {
        if(std::is_permutation(string, string+patternLength, pattern)) {
            if(!count) cout<<"Anagram:"<<endl;
            char * anagram = new char[patternLength+1];
            anagram[patternLength] = '\0';
            strncpy(anagram, string, patternLength);
            cout<<anagram<<" at index "<<i<<endl;
            count++;
        }
        string++;
    }
    if(!count) cout<<"Anagram does not found"<<endl;
}