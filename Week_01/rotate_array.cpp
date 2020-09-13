// 旋转数组

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()) {
            k = k%nums.size();
        }
        int j = 0;
        vector<int> num2(k);
        int s = nums.size()-k;
        for(int i = s;i< nums.size();++i) {
            num2[i-s] = nums[i];
        }
        for(int i = nums.size() - 1;i > k - 1 ; --i) {
            nums[i] = nums[i-k];
        }
        for(int i = 0 ;i < k;++i) {
            nums[i] = num2[i];
        }
        return ;
    }
};