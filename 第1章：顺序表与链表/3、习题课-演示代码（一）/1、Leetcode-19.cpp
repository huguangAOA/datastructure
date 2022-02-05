 
/*************************************************************************
   > File Name: 19.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/11 18:40:05 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = q = &ret;
    while (n--) { q = q->next; }
    q = q->next;
    while (q) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}