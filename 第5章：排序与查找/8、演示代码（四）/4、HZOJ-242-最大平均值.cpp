 
/*************************************************************************
   > File Name: 242.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/23 20:21:52 2019
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
#define MAX_N 100000
int arr[MAX_N + 5];

int check(int *arr, int n, int m, int a) {
    long long sj = 0, si = 0, pre_min = 0;
    for (int i = 0; i < m; i++) {
        sj += arr[i] - a;
    }
    if (sj >= 0) return 1;
    for (int i = m; i < n; i++) {
        si += arr[i - m] - a;
        pre_min = min(pre_min, si);
        sj += arr[i] - a;
        if (sj >= pre_min) return 1;
    }
    return 0;
}

int binary_search(int *arr, int n, int m, int l, int r) {
    if (l == r) return l;
    int mid = (l + r + 1) >> 1;
    if (check(arr, n, m, mid)) return binary_search(arr, n, m, mid, r);
    return binary_search(arr, n, m, l, mid - 1);
}

int main() {
    int n, m, min_num, max_num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 0) {
            min_num = max_num = arr[i];
        } else {
            if (min_num > arr[i]) min_num = arr[i];
            else if (max_num < arr[i]) max_num = arr[i];
        }
    }
    cout << binary_search(arr, n, m, min_num, max_num) << endl;
    return 0;
}