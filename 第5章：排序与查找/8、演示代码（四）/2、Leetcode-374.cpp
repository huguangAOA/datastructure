 
/*************************************************************************
   > File Name: 374.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 16:49:31 2019
 ************************************************************************/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int head = 1, tail = n, mid;
        while (head <= tail) {
            mid = head + ((tail - head) >> 1);
            int ret = guess(mid);
            if (ret == 0) return mid;
            if (ret < 0) tail = mid - 1;
            else head = mid + 1;
        }
        return -1;
    }
};