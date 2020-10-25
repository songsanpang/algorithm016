// hash法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> s_m;
        vector<int> res{-1,-1};
        for(int i = 0;i<nums.size();++i) {
            if(s_m.count(target-nums[i])>0) {
                res[0] =i;
                res[1] =s_m[target-nums[i]];
                return res;
            }
            s_m[nums[i]] = i;
        }
        return res;
    };
};