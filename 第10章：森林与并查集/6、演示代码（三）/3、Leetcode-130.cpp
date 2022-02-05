 
/*************************************************************************
   > File Name: 130.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 18:52:24 2019
 ************************************************************************/

typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->fa = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->fa[x] == x) return x;
    return (u->fa[x] = find(u, u->fa[x]));
}

void merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return ;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->fa[fb] = fa;
    u->size[fa] += u->size[fb];
    return ;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}

int getInd(int i, int j, int m) {
    return i * m + j + 1;
}

void solve(char** board, int n, int m) {
    UnionSet *u = init(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue;
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                merge(u, 0, getInd(i, j, m));
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                merge(u, getInd(i, j, m), getInd(i - 1, j, m));
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                merge(u, getInd(i, j, m), getInd(i, j - 1, m));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue;
            if (find(u, getInd(i, j, m)) != find(u, 0)) board[i][j] = 'X';
        }
    }
    clear(u);
    return ;
}