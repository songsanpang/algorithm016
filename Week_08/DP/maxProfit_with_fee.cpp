// leetcode : No.714. 买卖股票的最佳时机含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(!n) return 0;
        int dp[n][2];memset(dp,0,sizeof(dp));
        dp[0][0] = 0;dp[0][1] = -prices[0]-fee;
        for(int i{1};i<n;++i) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
};