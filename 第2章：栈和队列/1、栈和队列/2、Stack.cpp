 
/*************************************************************************
   > File Name: 4.stack.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  7/17 14:42:20 2019
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    printf("stack(%d) = [", s->top + 1);
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Stack *s = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 100;
        switch (op) {
            case 0: {
                printf("push %d to stack = %d\n", val, push(s, val));
            } break;
            case 1: {
                printf("pop %d from stack = %d\n", top(s), pop(s));
            }
        }
        output(s);
    }
    return 0;
}