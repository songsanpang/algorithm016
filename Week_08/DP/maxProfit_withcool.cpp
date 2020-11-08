// leetcode:309. 最佳买卖股票时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(!n) return 0;
        int pre{0},dp_0{0},dp_1{-prices[0]};
        for(int i{1};i<n;++i) {
            int tmp = dp_0;
            dp_0 = max(dp_0,dp_1+prices[i]);
            dp_1 = max(dp_1,pre - prices[i]);
            pre = tmp;
        }
        return dp_0;
    }