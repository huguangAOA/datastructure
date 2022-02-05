 
/*************************************************************************
   > File Name: 203.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 18:40:23 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode ret, *p = &ret, *q;
    ret.next = head;
    while (p && p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}