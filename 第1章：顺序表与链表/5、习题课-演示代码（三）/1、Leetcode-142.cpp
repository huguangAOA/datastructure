 
/*************************************************************************
   > File Name: 142.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 15:05:46 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    while (q) {
        p = p->next;
        q = q->next;
        if (q == NULL) return NULL;
        q = q->next;
        if (p == q) break;
    }
    if (q == NULL) return NULL;
    q = head;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}