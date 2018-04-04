#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void print_board(char *bombs, int len, int C) {
    for(int i = 0; i < len; i++) {
        if(i && !(i%C))
            printf("\n");
        if(bombs != NULL) {
            if(bombs[i] == 0)
                printf(".");
            else
                printf("O");
        }
        else
            printf("O");
    }
}

void detonate(char *bombs1, char *bombs2, int len, int C) {
    for(int i = 0; i < len; i++) {
        if(bombs1[i] == 1) {
            bombs2[i] = 0;
            if((i+1) % C)
                bombs2[i+1] = 0;
            if(i%C)
                bombs2[i-1] = 0;
            if(i-C >= 0)
                bombs2[i-C] = 0;
            if(i+C < len)
                bombs2[i+C] = 0;
        }
    }
}

int main() {
    int R, C, N;
    scanf("%d %d %d", &R, &C, &N);
    int len = R*C;
    char *bombs1 = (char*)calloc(len, sizeof(char));
    char *bombs2 = (char*)calloc(len, sizeof(char));
    char c;

    if(!(N % 2)) {
        print_board(NULL, len, C);
        return 0;
    }

    for(int i = 0; i < len; i++) {
        scanf(" %c", &c);
        if(c == 'O')
            bombs1[i] = 1;
        else if(c == '.')
            bombs2[i] = 1;
    }

    if(N == 1) {
        print_board(bombs1, len, C);
        return 0;
    }

    detonate(bombs1, bombs2, len, C);
    memset(bombs1, 1, len);
    detonate(bombs2, bombs1, len, C);

    if (N%4 == 3)
        print_board(bombs2, len, C);
    else
        print_board(bombs1, len, C);
    return 0;
}
