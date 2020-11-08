//leetcode:No.647 回文子串
class Solution {
public:
    int countSubstrings(string s) {
        int n = static_cast<int>(s.size());
        if(!n) return 0; 
        bool dp[n][n];memset(dp,0,sizeof(dp));
        for(int i{0};i<n;++i) dp[i][i] = true;
        int count {n};
        for(int j{1};j<n;j++) {
            for(int i{0}; i<j; ++i) {
                dp[i][j] = s[i] == s[j] && ( j-i < 3 || dp[i+1][j-1]);
                if(dp[i][j]) count ++;
            }
        }
        return count;
    }
};