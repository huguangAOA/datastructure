/*************************************************************************

    > File Name: 快速排序（非递归）

    > Author:    hug

    > Mail:      hug@haizeix.com

    > Created Time: 五  8/18 08:18:42 2017

************************************************************************/

 

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

#define MC(T, n) ((T *)malloc(sizeof(T) * n))

#define init_stack(s, n, T) (__init_stack(s, n, sizeof(T)))

#define push_stack(s, value) ({ \

    __typeof(value) __temp = (value); \

    __push_stack(s, (const char *)(&(__temp))); \

})

#define empty_stack(s) (__empty_stack(s))

#define pop_stack(s) (__pop_stack(s))

#define top_stack(s, T) (*((T *)__top_stack(s)))

#define clear_stack(s) (__clear_stack(s))

#define swap(a, b) { \

    __typeof(a) __temp = (a); \

    (a) = (b); (b) = (__temp); \

}

 

#define ERROR 0

#define OK 1

 

typedef struct Stack {

    char *data;

    int top, size;

    int value_size;

} Stack;

 

void __init_stack(Stack *s, int n, int value_size);

int __push_stack(Stack *s, const char *value);

int __empty_stack(Stack *s);

int __pop_stack(Stack *s);

char *__top_stack(Stack *s);

void __clear_stack(Stack *s);

 

typedef struct Node {

    int val;

    struct Node *lchild, *rchild;

} Node;

 

Node *init(int val) {

    Node *p = MC(Node, 1);

    p->val = val;

    p->lchild = p->rchild = NULL;

    return p;

}

 

typedef struct QuickSortArgs {

    int *arr;

    int l, r;

    int x;

    int status;

} QuickSortArgs;

 

int __quick_sort(int *arr, int l, int r) {

    // 0 : if (r <= l) return ;

    int x, y, z;

    x = l, y = r, z = arr[l];

    while (x < y) {

        while (x < y && arr[y] >= z) --y;

        if (x < y) arr[x++] = arr[y];

        while (x < y && arr[x] <= z) ++x;

        if (x < y) arr[y--] = arr[x];

    }

    arr[x] = z;

    return x;

    // 2: quick_sort(arr, l, x - 1);

    // 3 : quick_sort(arr, x + 1, r);

    // 4 : return ;

}

 

void init_quick_sort_args(QuickSortArgs *qsa, int *arr, int l, int r, int status) {

    qsa->arr = arr;

    qsa->l = l;

    qsa->r = r;

    qsa->status = 0;

    return ;

}

 

void quick_sort(int *arr, int n) {

    Stack *s = MC(Stack, 1);

    init_stack(s, 1000, QuickSortArgs);

    QuickSortArgs qsa;

    init_quick_sort_args(&qsa, arr, 0, n - 1, 0);

    push_stack(s, qsa);

    while (!empty_stack(s)) {

        QuickSortArgs *tqsa = &top_stack(s, QuickSortArgs);

        switch (tqsa->status) {

            case 0:

                if (tqsa->r <= tqsa->l) {

                    tqsa->status = 4;

                } else {

                    tqsa->status = 1;

                }

                break;

            case 1:

                tqsa->x = __quick_sort(tqsa->arr, tqsa->l, tqsa->r);

                tqsa->status = 2;

                break;

            case 2:

                init_quick_sort_args(&qsa, arr, tqsa->l, tqsa->x - 1, 0);

                push_stack(s, qsa);

                tqsa->status = 3;

                break;

            case 3:

                init_quick_sort_args(&qsa, arr, tqsa->x + 1, tqsa->r, 0);

                push_stack(s, qsa);

                tqsa->status = 4;

                break;

            case 4:

                pop_stack(s);

                break;

            default:

                printf("ERROR\n");

                break;

        }

    }

    return ;

}

 

int main() {

    int arr[10] = {9, 7, 5, 4, 2 ,1 ,3, 10, 6, 8};

    quick_sort(arr, 10);

    for (int i = 0; i < 10; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

    return 0;

}

 

void __init_stack(Stack *s, int n, int value_size) {

    s->data = (char *)malloc(value_size * n);

    s->top = -1;

    s->size = n;

    s->value_size = value_size;

    return ;

}

 

int __push_stack(Stack *s, const char *value) {

    if (s->top == s->size - 1) {

        return ERROR;

    }

    ++(s->top);

    memcpy(s->data + s->top * s->value_size, value, s->value_size);

    return OK;

}

 

int __empty_stack(Stack *s) {

    return s->top == -1;

}

 

int __pop_stack(Stack *s) {

    if (__empty_stack(s)) {

        return ERROR;

    }

    --(s->top);

    return OK;

}

 

char *__top_stack(Stack *s) {

    if (__empty_stack(s)) {

        return NULL;

    }

    return s->data + s->top * s->value_size;

}

 

void __clear_stack(Stack *s) {

    free(s->data);

    free(s);

    return ;

}