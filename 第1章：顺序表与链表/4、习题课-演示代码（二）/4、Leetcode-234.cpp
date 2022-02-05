 
/*************************************************************************
   > File Name: 234.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 19:02:26 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int get_length(struct ListNode *head) {
    int n = 0;
    while (head) n += 1, head = head->next;
    return n;
}

struct ListNode *get_node(struct ListNode *head, int ind) {
    while (ind--) head = head->next;
    return head;
}

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode ret, *p = head, *q;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head) {
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(get_node(head, (len + 1) / 2));
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}