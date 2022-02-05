 
/*************************************************************************
   > File Name: 684.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 19:24:39 2019
 ************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MC(T, n) (T *)malloc(sizeof(T) * (n))
#define CC(T, n) (T *)calloc(sizeof(T), (n))

typedef struct UnionSet {
    int *fa;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = MC(UnionSet, 1);
    u->fa = MC(int, n + 1);
    u->n = n;
    for (int i = 1; i <= n; i++) u->fa[i] = i;
    return u;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u);
    return ;
}

int get(UnionSet *u, int x) {
    if (u->fa[x] == x) return x;
    return u->fa[x] = get(u, u->fa[x]);
}

int merge(UnionSet *u, int a, int b) {
    u->n -= (get(u, a) != get(u, b));
    u->fa[get(u, a)] = get(u, b);
    return u->n;
}

int* findRedundantConnection(int** edges, int n, int *m, int* rs) {
    UnionSet *u = init(n);
    int *ret = MC(int, 2);
    for (int i = 0; i < n; i++) {
        if (u->n == merge(u, edges[i][0], edges[i][1])) {
            ret[0] = edges[i][0];
            ret[1] = edges[i][1];
            break;
        }
    }
    *rs = 2;
    return ret;
}