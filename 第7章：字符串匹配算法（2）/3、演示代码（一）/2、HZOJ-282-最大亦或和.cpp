 
/*************************************************************************
   > File Name: 282.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  8/21 16:25:46 2019
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
#define MAX_N 320000
#define BASE 30

struct Node {
    int num;
    int next[2];
} tree[MAX_N + 5];
int root = 1, cnt = 1;
int arr[(MAX_N >> 5 )+ 5];
inline int getNode() { return ++cnt; }
void insert(int num) {
    int p = root;
    for (int i = BASE; i >= 0; --i) {
        int ind = !!((1 << i) & num);
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].num = num;
    return ;
}

int query(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        int rind = !ind;
        if (tree[p].next[rind]) p = tree[p].next[rind];
        else p = tree[p].next[ind];
    }
    return num ^ tree[p].num;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], insert(arr[i]);
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    cout << ans << endl;
    return 0;
}