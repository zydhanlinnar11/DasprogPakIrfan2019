#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
short destx, desty, movex[] = {2, 2, -2, -2, 1, -1, 1, -1}, movey[] = {1, -1, 1, -1, 2, 2, -2, -2};
int minstep = INT_MAX, visited[8][8];

void getshortest(short x, short y, int step) {
    if(x == destx && y == desty) {
        if(step < minstep) minstep = step;
    } else if(visited[x][y] <= step || x > 7 || y > 7 || x < 0 || y < 0) return;
    else {
        visited[x][y] = step;
        for(int i = 0; i < 8; i++) {
            getshortest(x + movex[i], y + movey[i], step + 1);
        }
    }
}

int main() {
    short x, y;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            visited[i][j] = INT_MAX;
        }
    }
    scanf("%hd%*c%hd", &x, &y);
    scanf("%hd%*c%hd", &destx, &desty);
    getshortest(x, y, 0);
    printf("%d\n", minstep);
    return 0;
}