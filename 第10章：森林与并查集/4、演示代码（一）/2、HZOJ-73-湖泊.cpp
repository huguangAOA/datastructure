 
/*************************************************************************
   > File Name: 73.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  8/22 14:19:28 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 1000
#define MAX_M 1000000
#define ind(i, j) ((i) * (m) + (j) + 1)
char g[MAX_N + 5][MAX_N + 5];

struct UnionSet {
    int fa[MAX_M + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (i && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (j && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (u.get(ind(i, j)) - u.get(0)) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}