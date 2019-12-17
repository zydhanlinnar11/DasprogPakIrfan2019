#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listnode {
    int value;
    struct listnode *nextPtr;
};

typedef struct listnode ListNode;
typedef ListNode * ListNodePtr;

void randomnumber(int * a);
void insertNode(ListNodePtr *sPtr, int value);
void printNode(ListNodePtr sPtr);

int main() {
    ListNodePtr startPtr = NULL;
    int *a = malloc(10*sizeof(int));
    srand(time(NULL));
    randomnumber(a);
    int i;
    for (i=0; i<10; i++ ) {
        insertNode(&startPtr, a[i]);
    }
    printNode(startPtr);
    printf("Input an integer: ");
    int number;
    scanf("%d", &number);
    insertNode(&startPtr, number);
    printNode(startPtr);

    return 0;
}

void randomnumber(int * a) {
    int i;
    for(i=0; i<10; i++) {
        a[i] = rand() % 10;
    }
}

void insertNode(ListNodePtr *sPtr, int value) {
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr newPtr;

    newPtr = malloc(sizeof(ListNode));

    if(newPtr != NULL) {
        newPtr->value = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while( currentPtr!=NULL && value > currentPtr->value ) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr==NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr=currentPtr;
        }
    } else {
        printf("Memory not available\n");
    }


}

void printNode(ListNodePtr sPtr) {
    printf( "The list is:\n" );

    /* while not the end of the list */
    while ( sPtr != NULL ) {
        printf( "%d --> ", sPtr->value );
        sPtr = sPtr->nextPtr;
    } /* end while */

    printf( "NULL\n\n" );
}