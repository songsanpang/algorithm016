class Solution {
public:
    bool isPerfectSquare(int num) {
        long long min{0};
        long long max = num>>1|1;
        while ( min <= max) {
            long long mid = (max + min) >> 1 ;
            long long tmp = mid*mid;
            if (tmp == num) return true;
            if(tmp < num) min = mid +1;
            else max = mid -1;
        }
        return false;
    }
};