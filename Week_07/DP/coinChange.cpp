//first
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int record[amount+1];
        for(int i{0} ;i <= amount;++i) record[i] = amount+1;
        record[0] = 0;
        for(int i{1} ;i <= amount;++i ) {
            for(auto coin :coins) {
                if(coin > i) continue;
                if(record[i - coin] != -1) record[i] = min(record[i],1+record[i - coin]);
            }
            if(record[i] == amount+1) record[i] = -1;
        } 
        return record[amount] == amount+1 ? -1 : record[amount];
    }
};
