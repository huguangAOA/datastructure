 
/*************************************************************************
   > File Name: 253.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 二  6/18 19:31:12 2019
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
#define MAX_N 2500
struct Range {
    int l, r;
} arr[MAX_N + 5], item[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    return a.r < b.r;
}

int main() {
    int n, l;
    cin >> n >> l; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    for (int i = 0; i < l; i++) {
        cin >> item[i].l >> item[i].r;
    }
    sort(arr, arr + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0, ind = -1;
        for (int j = 0; j < l; j++) {
            if (item[j].r == 0) continue;
            if (item[j].l < arr[i].l || item[j].l > arr[i].r) continue;
            if (ind == -1) {
                ind = j;
                flag = 1;
                continue;
            }
            if (item[j].l < item[ind].l) ind = j;
        }
        if (flag) item[ind].r -= 1;
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}