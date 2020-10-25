class Solution {
public:
    int mySqrt(int x) {
        long long min=0;//防止溢出
        long long max=x/2+1;
        while(min<=max) // 相等时候也要保证**2<x
        {
            long long mid=(min+max)/2;
            long long tmp=mid*mid;
            if(tmp == x ) return mid;
            else if(tmp <x) min=mid+1;
            else max=mid-1;
        }
        return max;
    }
};
