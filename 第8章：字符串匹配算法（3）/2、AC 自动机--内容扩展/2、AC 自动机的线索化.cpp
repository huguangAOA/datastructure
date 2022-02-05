 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 200000;
const int MAX_LEN = 200000;
char str_buffer[200005];

typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode *fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)calloc(sizeof(TrieNode), 1);
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->count = 0;
    return p;
}

void clear(TrieNode *node) {
    if (node == NULL) return ;
    for (int i = 0; i < SIZE; i++) {
        if (node->childs[i] == NULL) continue;
        clear(node->childs[i]);
    }
    free(node->childs);
    free(node);
    return ;
}

void insert(TrieNode *trie, const char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count++;
    return ;
}

void build_automaton(TrieNode *node) {
    TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode *) * (MAX_SIZE + 5));
    int head = 0, tail = 0;
    queue[tail++] = node;
    while (head < tail) {
        TrieNode *now = queue[head++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] == NULL) {
                if (now != node) now->childs[i] = now->fail->childs[i];
                continue;
            }
            TrieNode *p = (now->fail ? now->fail->childs[i] : node);
            if (p == NULL) p = node;
            now->childs[i]->fail = p;
            queue[tail++] = now->childs[i];
        }
    }
    free(queue);
    return ;
}

int match_count(TrieNode *ac_tree, const char *str) {
    int ret = 0;
    TrieNode *p = ac_tree, *q;
    while (str[0]) {
        p = p->childs[str[0] - 'a'];
        q = p;
        while (q) ret += q->count, q = q->fail;
        if (p == NULL) p = ac_tree;
        str++;
    }
    return ret;
}
int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[MAX_LEN];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    printf("insert done\n");
    fflush(stdout);
    build_automaton(root);
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    //clear(root);
    return 0;
}