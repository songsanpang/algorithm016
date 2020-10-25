// //greed
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() <= 1) return 0;
//         int maxfit{0};
//         for(int i{1} ; i<prices.size() ; ++i) {
//             maxfit += max(0,prices[i] - prices[i-1]); 
//         }
//         return maxfit;
//     }
// };

// // dp
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() <= 1) return 0;
//         int dp [prices.size()][2];
//         dp[0][0] = 0;
//         dp[0][1] = -prices[0];
//         for(int i{1} ; i<prices.size() ; ++i) {
//             dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]); 
//             dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
//         }
//         return dp[prices.size()-1][0];
//     }
// };