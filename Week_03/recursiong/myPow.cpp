class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n == -1) return 1/x;
        double tmp = myPow(x,n>>1);
        return n%2 == 0 ? tmp*tmp : tmp*tmp*x; 
    }
};