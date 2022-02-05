 
/*************************************************************************
   > File Name: 287.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  8/12 19:10:24 2019
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

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a, q.push(a);
    for (int i = 1; i < n; i++) {
        int val1 = q.top(); q.pop();
        int val2 = q.top(); q.pop();
        q.push(val1 + val2);
        sum += val1 + val2;
    }
    cout << sum << endl;
    return 0;
}