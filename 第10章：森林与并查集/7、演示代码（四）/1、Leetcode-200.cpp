 
/*************************************************************************
   > File Name: 200.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 19:08:07 2019
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
    u->fa[get(u, a)] = get(u, b);
}

int numIslands(char** grid, int n, int *M) {
    if (n == 0) return 0;
    int m = M[0];
    #define ind(i, j) ((i) * (m) + (j) + 1)
    UnionSet *u = init(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') continue;
            if (i - 1 >= 0 && grid[i - 1][j] == '1')
                merge(u, ind(i, j), ind(i - 1, j));
            if (j - 1 >= 0 && grid[i][j - 1] == '1')
                merge(u, ind(i, j), ind(i, j - 1));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') continue;
            ans += (get(u, ind(i, j)) == ind(i, j));
        }
    }
    clear(u);
    return ans;
}