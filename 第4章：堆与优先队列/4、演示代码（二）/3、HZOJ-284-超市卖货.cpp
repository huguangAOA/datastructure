 
/*************************************************************************
   > File Name: 284.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  8/12 19:47:15 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
using namespace std;
#define MAX_N 10000

struct Data {
    int p, d;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.d < b.d;
}

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].p >> arr[i].d;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, arr[i].d));
        } else if (arr[i].p > s.begin()->first) {
            s.insert(PII(arr[i].p, s.begin()->second));
            s.erase(s.begin());
        }
    }
    int sum = 0;
    cout << "-----------" << endl;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        sum += iter->first;
        cout << iter->first << " " << iter->second << endl;
    }
    cout << sum << endl;
    return 0;
}