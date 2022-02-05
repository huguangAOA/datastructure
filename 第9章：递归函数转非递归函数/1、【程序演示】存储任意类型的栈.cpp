/*************************************************************************
   > File Name: 15.any_stack.h
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  2/28 10:49:10 2018
 ************************************************************************/

#ifndef _15_ANY_STACK_H
#define _15_ANY_STACK_H

#include <stdlib.h>
#include <string.h>

#define STACK_OK 1
#define STACK_ERROR 0

typedef struct Stack {
    char *data;
    int data_size;
    int size, top;
} Stack;

#define init_stack(n, T) (__init_stack(n, sizeof(T)))
#define push_stack(s, data) (__push_stack(s, (char *)(data)))
#define top_stack(s, T) ((T *)(__top_stack(s)))

Stack *__init_stack(int n, int data_size) {
    Stack *s = (Stack *)malloc(sizeof(Stack) * 1);
    s->data = (char *)malloc(n * data_size);
    s->data_size = data_size;
    s->size = n;
    s->top = -1;
    return s;
}

int __push_stack(Stack *s, char *data) {
    if (s->size - 1 == s->top) {
        return STACK_ERROR;
    }
    s->top += 1;
    memcpy(s->data + s->top * s->data_size, data, s->data_size);
    return STACK_OK;
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

char *__top_stack(Stack *s) {
    if (empty_stack(s)) {
        return NULL;
    }
    return s->data + s->top * s->data_size;
}

int pop_stack(Stack *s) {
    if (empty_stack(s)) {
        return STACK_ERROR;
    }
    s->top -= 1;
    return STACK_OK;
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
    return ;
}

#endif