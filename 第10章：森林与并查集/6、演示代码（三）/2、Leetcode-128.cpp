 
/*************************************************************************
   > File Name: 128.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 18:48:22 2019
 ************************************************************************/
#define MC(T, n) (T *)malloc(sizeof(T) * (n))
#define CC(T, n) (T *)calloc(sizeof(T), (n))

typedef struct Node {
    int val, ind;
} Node;

typedef struct HashTable {
    Node *data;
    int *flag;
    int n;
} HashTable;

typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
} UnionSet;

UnionSet *init_UnionSet(int n) {
    UnionSet *u = MC(UnionSet, 1);
    u->fa = MC(int, n);
    u->size = MC(int, n);
    for (int i = 0; i < n; i++) u->fa[i] = i, u->size[i] = 1;
    u->n = n;
    return u;
}

void clear_UnionSet(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}

HashTable *init_HashTable(int n) {
    HashTable *h = MC(HashTable, 1);
    h->data = MC(Node, n);
    h->flag = CC(int, n / 31 + 1);
    h->n = n;
    return h;
}

void clear_HashTable(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int get(UnionSet *u, int x) {
    if (u->fa[x] == x) return x;
    return u->fa[x] = get(u, u->fa[x]);
}

void merge(UnionSet *u, int a, int b) {
    int aa = get(u, a), bb = get(u, b);
    if (aa == bb) return ;
    u->fa[aa] = bb;
    u->size[bb] += u->size[aa];
    return ;
}

int hash(int val) {
    return val & 0x7fffffff;
}

int check(HashTable *h, int ind) {
    int x = ind / 31, y = ind % 31;
    return h->flag[x] & (1 << y);
}

void set_HashTable(HashTable *h, int now, int val, int ind) {
    int x = now / 31, y = now % 31;
    h->flag[x] |= (1 << y);
    h->data[now].val = val;
    h->data[now].ind = ind;
    return ;
}

int insert(HashTable *h, int val, int ind) {
    int now = hash(val) % h->n;
    int time = 1;
    while (check(h, now) && h->data[now].val != val) {
        now += (time * time);
        now %= h->n;
        time++;
    }
    if (check(h, now)) return 0;
    set_HashTable(h, now, val, ind);
    return 1;
}

int query(HashTable *h, int val) {
    int now = hash(val) % h->n;
    int time = 1;
    while (check(h, now) && h->data[now].val != val) {
        now += (time * time);
        now %= h->n;
        time++;
    }
    if (check(h, now)) return h->data[now].ind;
    return -1;
}

int longestConsecutive(int* nums, int n) {
    HashTable *h = init_HashTable(n * 3);
    UnionSet *u = init_UnionSet(n);
    for (int i = 0; i < n; i++) {
        if (!insert(h, nums[i], i)) continue;
        int ind1 = query(h, nums[i] + 1);
        int ind2 = query(h, nums[i] - 1);
        if (ind1 != -1) merge(u, i, ind1);
        if (ind2 != -1) merge(u, i, ind2);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u->size[i] > ans) ans = u->size[i];
    }
    clear_UnionSet(u);
    clear_HashTable(h);
    return ans;
}