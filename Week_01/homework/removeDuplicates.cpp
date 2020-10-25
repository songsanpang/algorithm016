class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if(N == 0 || N == 1) return nums.size();
        int j =0;
        for(int i =1; i <N; ++i){
            if(nums[i] !=nums[i-1]) nums[++j] = nums[i];
        }
        // for(int count = j+1; count <nums.size();count++) nums.pop_back();
        return j+1;
    }
};