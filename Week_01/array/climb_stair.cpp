//特征值法
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)(fibn / sqrt5);
    }
};


//暴力法
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n==1) return 1;
//         if (n==2) return 2;
//         return climbStairs(n-2) + climbStairs(n-1);
//     }
// };

//缓存法
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> result;
//         result.push_back(1);
//         result.push_back(1);
//         int ff;
//         for(int i=2;i<=n ;++i) {
//             ff = result[i-1]+result[i-2];
//             result.push_back(ff);
//         }
//         return result[n];
//     }
// };
