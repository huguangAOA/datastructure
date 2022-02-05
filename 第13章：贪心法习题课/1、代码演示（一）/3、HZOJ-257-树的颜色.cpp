 
/*************************************************************************
   > File Name: 257.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 二  6/18 20:36:44 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define MAX_N 1000

struct Node {
    int father, head, tail;
    int val, cnt;
};

bool operator<(const Node &a, const Node &b) {
    return a.val * b.cnt < a.cnt * b.val;
}

struct UnionSet {
    int fa[MAX_N + 5];
    Node arr[MAX_N + 5];
    int ans[MAX_N + 5];
    inline void init(int n) {
        for (int i = 1 ; i <= n; i++) {
            fa[i] = i;
            ans[i] = 0;
            arr[i].father = 0;
            arr[i].head = arr[i].tail = i;
            arr[i].cnt = 1;
        }
    }
    int get(int x) {
        return (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[bb] = aa;
        ans[arr[aa].tail] = arr[bb].head;
        arr[aa].tail = arr[bb].tail;
        arr[aa].val += arr[bb].val;
        arr[aa].cnt += arr[bb].cnt;
        return ;
    }
};

UnionSet u;
priority_queue<Node> que;

int val[MAX_N + 5];

int main() {
    int n, r;
    cin >> n >> r;
    u.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        u.arr[i].val = val[i];
        que.push(u.arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        u.arr[b].father = a;
    }
    while (!que.empty()) {
        int ind = que.top().head, fa = u.arr[ind].father;
        que.pop();
        if (fa == 0) continue;
        u.merge(fa, ind);
        que.push(u.arr[u.get(ind)]);
    }
    int p = r, t = 1, ans = 0;
    while (p) {
        ans += val[p] * t;
        p = u.ans[p];
        t++;        
    }
    cout << ans << endl;
    return 0;
}