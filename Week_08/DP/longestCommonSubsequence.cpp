// leetcode : No.1143最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if(m ==0 || n == 0) return 0;
        int dp[m+1][n+1];memset(dp,0,sizeof(dp));
        for(int i{0};i<m;++i) { // 注意字符串末尾的那个0
            for(int j{0};j<n;++j) {
                if(text1[i] == text2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[m][n];
    }
};