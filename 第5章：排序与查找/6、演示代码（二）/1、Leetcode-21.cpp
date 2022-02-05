 
/*************************************************************************
   > File Name: 21.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 14:49:13 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode ret, *p, *q, *t;
    ret.next = NULL;
    t = &ret;
    p = l1, q = l2;
    while (p || q) {
        if (q == NULL || (p && p->val <= q->val)) {
            t->next = p; p = p->next; t = t->next;
        } else {
            t->next = q; q = q->next; t = t->next;
        }
    }
    return ret.next;
}