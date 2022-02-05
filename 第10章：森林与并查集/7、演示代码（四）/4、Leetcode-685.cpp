 
/*************************************************************************
   > File Name: 685.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 19:49:43 2019
 ************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
    int cnt;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->fa = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    u->n = n;
    u->cnt = n;
    for (int i = 0; i < n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    if (u->fa[x] == x) return x;
    return (u->fa[x] = find(u, u->fa[x]));
}

int merge(UnionSet *u, int a, int b) {
    int f[2] = { find(u, a), find(u, b) };
    if (f[1] == f[0]) return 0;
    int flag = (u->size[f[0]] > u->size[f[1]]);
    u->fa[f[flag]] = f[!flag];
    u->size[f[!flag]] += u->size[f[flag]];
    u->cnt -= 1;
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}

int* findRedundantDirectedConnection(int** edges, int n, int m, int* returnSize) {
    int *ret = (int *)calloc(sizeof(int), 2);
    *returnSize = 2;
    int *indeg = (int *)calloc(sizeof(int), n + 1);
    int *outdeg = (int *)calloc(sizeof(int), n + 1);
    int *father = (int *)calloc(sizeof(int), n + 1);
    int *queue = (int *)calloc(sizeof(int), n + 1);
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        indeg[edges[i][1]] += 1;
        outdeg[edges[i][0]] += 1;
        father[edges[i][1]] = edges[i][0];
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        flag = (indeg[i] == 2);
        if (flag) { flag = i; break; }
    }
    if (flag) {
        for (int i = n - 1; i >= 0; --i) {
            if (edges[i][1] - flag) continue;
            UnionSet *u = init(n + 1);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                merge(u, edges[j][0], edges[j][1]);
            }
            if (u->cnt != 2) {
                clear(u);
                continue;
            }
            ret[0] = edges[i][0];
            ret[1] = edges[i][1];
            clear(u);
            break;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (outdeg[i]) continue;
            queue[tail++] = i;
        }
        while (head < tail) {
            int ind = queue[head++];
            if (!(--outdeg[father[ind]])) queue[tail++] = father[ind];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (outdeg[edges[i][0]] && outdeg[edges[i][1]]) {
                ret[0] = edges[i][0];
                ret[1] = edges[i][1];
                break;
            }
        }
    }
    return ret;
}