class Solution {
public:
    int jump(vector<int>& nums) {
        int end{0},cnt{0},maxt{0};
        for(int i = 0; i<nums.size()-1 ;++i) {
            if (end >= nums.size()-1) return cnt;
            maxt = max(maxt,nums[i]+i);
            if(i == end) {
                end = maxt;
                cnt++;    
            }
        }
        return cnt;
    }
};
