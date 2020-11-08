//  leetcode : No.123. 买卖股票的最佳时机 III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int dp[n][3][2];memset(dp,0,sizeof(dp));
        dp[0][1][0] = -prices[0];
        dp[0][0][1] = -prices[0];
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = -prices[0];
        for(int i{1};i<n;++i) {
        dp[i][0][1] = max(dp[i-1][0][1], - prices[i]);
        dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][0][1] + prices[i]);
        dp[i][1][1] = max(dp[i-1][1][1],dp[i-1][1][0] - prices[i]);
        dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][1][1] + prices[i]);
        }
        int res = max(dp[n-1][2][0],dp[n-1][1][0]);
        return res>0?res:0;
    }
};