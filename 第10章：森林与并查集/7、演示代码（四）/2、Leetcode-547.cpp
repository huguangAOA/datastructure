 
/*************************************************************************
   > File Name: 547.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 19:17:29 2019
 ************************************************************************/

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

void merge(UnionSet *u, int a, int b) {
    u->n -= (get(u, a) != get(u, b));
    u->fa[get(u, a)] = get(u, b);
}

int findCircleNum(int** M, int n, int *m) {
    if (n == 0) return 0;
    UnionSet *u = init(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 0) continue;
            merge(u, i + 1, j + 1);
        }
    }
    int ans = u->n;
    clear(u);
    return ans;
}