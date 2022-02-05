 
/*************************************************************************
   > File Name: 278.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 16:18:01 2019
 ************************************************************************/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int head = 1, tail = n, mid;
    while (head < tail) {
        mid = head + ((tail - head) >> 1);
        if (isBadVersion(mid)) tail = mid;
        else head = mid + 1;
    }
    return head;
}