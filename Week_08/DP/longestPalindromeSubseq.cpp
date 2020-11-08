// leetcode:No.516最长回文子序列
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = static_cast<int>(s.size());
        if(!n) return 0;
        int dp[n][n];memset(dp,0,sizeof(dp));
        for(int i{0};i<n;++i) dp[i][i] = 1;
        for(int i{n-2};i>=0;--i) {//计算方向一定要清楚，不然编译器也不报错，调错调到崩溃
            for(int j= i+1;j<n;++j) {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] +2;
                else dp[i][j] = max(dp[i+1][j] ,dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};