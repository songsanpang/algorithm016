// leetcode : 122. 买卖股票的最佳时机 II
// greed
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n == 0) return 0;
//         int maxfit {0};
//         for(int i{1};i<n ;++i) {
//             if(prices[i-1] < prices[i]) maxfit += prices[i] - prices[i-1];
//         }
//         return maxfit;
//     }
// };


// // dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        // int dp[n][2];memset(dp,0,sizeof(dp));
        // dp[0][0] = 0;dp[0][1] = -prices[0];
        int profit0{0},profit1{-prices[0]};
        for(int i{1};i<n;++i) {
            int newprofit0 = max(profit0,profit1+prices[i]);
            int newprofit1 = max(profit1,profit0-prices[i]);
            profit0 = newprofit0;
            profit1 = newprofit1;
            // dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            // dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }
        // return dp[n-1][0];
        return profit0;
    }
};