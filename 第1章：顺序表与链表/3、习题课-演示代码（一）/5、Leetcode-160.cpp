 
/*************************************************************************
   > File Name: 160.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 16:57:43 2019
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;    
    while (p != q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }
    return p;
}