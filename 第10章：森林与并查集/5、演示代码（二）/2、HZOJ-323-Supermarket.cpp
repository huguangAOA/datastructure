 
/*************************************************************************
   > File Name: 323.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  8/22 18:15:11 2019
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
#define MAX_N 10000

struct Data {
    int p, d;
} arr[MAX_N + 5];

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};


bool cmp(const Data &a, const Data &b) {
    return a.p > b.p;
}

UnionSet u;

int solve() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    u.init(MAX_N);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u.get(arr[i].d) == 0) continue;
        ans += arr[i].p;
        int day = u.get(arr[i].d);
        u.merge(day, day - 1);
    }
    cout << ans << endl;
    return 1;
}

int main() {
    while (solve()) ;
    return 0;
}