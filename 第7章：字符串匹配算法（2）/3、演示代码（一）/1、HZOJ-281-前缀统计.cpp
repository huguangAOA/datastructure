 
/*************************************************************************
   > File Name: 281.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  8/21 16:07:35 2019
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
#define MAX_N 1000000

struct Node {
    int flag;
    int next[26];
} tree[MAX_N + 5];
int root = 1, cnt = 1;
char str[MAX_N + 5];

int getNode() { return ++cnt; }
void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag += 1;
    return ;
}

int query(const char *str) {
    int p = root, cnt = 0;
    for (int i = 0; str[i] && p; i++) {
        p = tree[p].next[str[i] - 'a'];
        cnt += tree[p].flag;
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) cin >> str, insert(str);
    while (m--) cin >> str, cout << query(str) << endl;
    return 0;
}