class Solution {
public
    vectorvectorint result;
    vectorint tmp;
    void trace_back(vectorint& nums, int start) {
        result.push_back(tmp);
        for(int i = start ; i  nums.size() ;++i){
            tmp.push_back(nums[i]);
            trace_back(nums,i+1);
            tmp.pop_back();
        }
    }
    vectorvectorint subsets(vectorint& nums) {
        trace_back(nums,0);
        return result;
    }
};