#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int data;
    struct treenode *upperPtr;
    struct treenode *downleftPtr;
    struct treenode *downrightPtr;
};

typedef struct treenode Node;
typedef Node * NodePtr;

void insert(NodePtr * sPtr, int data, char pos) {
    NodePtr currentPtr;
    currentPtr = *sPtr;
    if(pos == 'r') {
        NodePtr downRight;
        downRight = malloc(sizeof(Node));
        downRight->data=data;
        downRight->downleftPtr = NULL;
        downRight->downrightPtr = NULL;
        downRight->upperPtr = *sPtr;
        currentPtr->downrightPtr = downRight;
        *sPtr = downRight;
    } else {
        NodePtr downLeft;
        downLeft = malloc(sizeof(Node));
        downLeft->data=data;
        downLeft->downleftPtr = NULL;
        downLeft->downrightPtr = NULL;
        downLeft->upperPtr = *sPtr;
        currentPtr->downleftPtr = downLeft;
        *sPtr = downLeft;
    }
}

void printnode(NodePtr sPtr, int before) {
    if(sPtr->downleftPtr == NULL && sPtr->downleftPtr == NULL) {
        printf("leaf: %d\n", sPtr->data + before);
    } else {
        printf("node: %d\n", sPtr->data);
        printnode(sPtr->downleftPtr, before + sPtr->data);
        printnode(sPtr->downrightPtr, before + sPtr->data);
    }
}

int main() {
    NodePtr startPtr = NULL;
    int data;
    FILE *file;
    file = fopen("02_file_input.txt", "r");
    if(file!=NULL) {
        while(!feof(file)) {
            char line;
            fscanf(file," %c", &line);
            if(line == 'r' || line == 'l') {
                fscanf(file, "%d", &data);
                insert(&startPtr, data, line);
            } else if(line == 'u') {
                startPtr = startPtr->upperPtr;
            } else {
                fscanf(file, "%d", &data);
                startPtr = malloc(sizeof(Node));
                startPtr->data = data;
                startPtr->downleftPtr = NULL;
                startPtr->downrightPtr = NULL;
                startPtr->upperPtr = NULL;
            }
        }
    } else {
        puts("02_file_input.txt not found");
    }
    while(startPtr->upperPtr != NULL) {
        startPtr = startPtr->upperPtr;
    }
    printnode(startPtr, 0);
}