 
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
#include <set>
using namespace std;

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n, a, sum = 0;
    cin >> n;
    while (n--) cin >> a, s.insert(PII(a, n));
    while (s.size() != 1) {
        int val1 = s.begin()->first; s.erase(s.begin());
        int val2 = s.begin()->first; s.erase(s.begin());
        s.insert(PII(val1 + val2, n--));
        sum += val1 + val2;
    }
    cout << sum << endl;
    return 0;
}