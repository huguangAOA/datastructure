 
/*************************************************************************
   > File Name: 232.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/11 18:58:05 2019
 ************************************************************************/

typedef struct {
    int *data;
    int top;
} MyStack;

MyStack* myStackCreate(int maxSize) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * maxSize);
    s->top = -1;
    return s;
}

/** Push element x to the back of queue. */
void myStackPush(MyStack* obj, int x) {
    obj->data[++(obj->top)] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->data[(obj->top)--];
}

/** Get the front element. */
int myStackTop(MyStack* obj) {
   return obj->data[obj->top]; 
}

/** Returns whether the queue is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}


typedef struct {
    MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = myStackCreate(maxSize);
    q->s2 = myStackCreate(maxSize);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackPop(obj->s2);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj->s1) && myStackEmpty(obj->s2); 
}

void myQueueFree(MyQueue* obj) {
    myStackFree(obj->s1);
    myStackFree(obj->s2);
    free(obj);
    return ;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */