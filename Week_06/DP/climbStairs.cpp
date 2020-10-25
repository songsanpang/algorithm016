//dp法
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        int pre{1},now{1},tmp; 
        for(int i=2 ;i<= n ;i++) {
            tmp = now;
            now += pre;
            pre = tmp;
        }
        return now;
    }
};