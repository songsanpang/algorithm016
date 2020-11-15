// leetcode ：No.121. 买卖股票的最佳时机
// 贪心
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n == 0) return 0;
//         int min = prices[0],profit{0};
//         for(int i{1};i<n ;++i) {
//             if(prices[i] < min) min = prices[i];
//             profit = max(prices[i] - min,profit);
//         }
//     return profit;
//     }
// };
// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        // int dp[n][2];memset(dp,0,sizeof(dp));
        // dp[0][1] = -prices[0];
        int profit0 = 0,profit1 = -prices[0];

        for(int i{1};i<n;++i) {
            // dp[i][0] = max(dp[i-1][0] , dp[i-1][1] + prices[i]);
            // dp[i][1] = max(dp[i-1][1],-prices[i]);
            profit0 = max(profit0,profit1 + prices[i]);
            profit1 = max(profit1,-prices[i]);
        }
        // return dp[n-1][0];
        return profit0;
    }
};