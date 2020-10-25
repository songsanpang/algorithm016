class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist;
        for(int i{0} ; i< nums.size() ; ++i) {
            if(i > dist) return false ;
            dist = max(nums[i] + i, dist);
        }
        return true;
    }
};

