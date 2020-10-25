class Solution {
public:
    void rotate_array(vector<int>& nums, int k) {
        int N = nums.size();
        int temp = N-k;
        vector<int> nums_kcopy(k);
        for(int i =0; i <k; ++i){
            nums_kcopy[i] = nums[temp+i];
        }
        for(int i =N-1; i >= k; --i) {
            nums[i] = nums[i-k];
        }
        for(int i = 0;i<k;++i){
            nums[i]=nums_kcopy[i];
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if(N>k) rotate_array(nums,k);
        else rotate(nums,k%N);
    }
};