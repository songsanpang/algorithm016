class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    void backtrace (vector<int>& nums) {
        if(nums.size() == tmp.size()) {
            result.push_back(tmp);
            return ;
        }
        for(auto i : nums) {
            auto a = find(tmp.begin(),tmp.end(),i);
            if (a!=tmp.end()) continue;
            tmp.push_back(i);
            backtrace(nums);
            tmp.pop_back();
        }
        return ; 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrace(nums);
        return result;
    }
};