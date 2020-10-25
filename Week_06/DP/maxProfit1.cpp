class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minprice= prices[0],maxfit{0};
        for(int i{1};i<prices.size();++i) {
            if(prices[i] - minprice > maxfit ) maxfit = prices[i] - minprice;
            if(minprice > prices[i]) minprice = prices[i];
        }
        return maxfit;
    }
};