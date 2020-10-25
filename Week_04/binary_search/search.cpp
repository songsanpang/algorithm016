class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        if(n == 1) return nums[0] == target ? 0: -1;
        
        int min{0},max{n-1};
        while (min <= max) {
            int mid = (min+max)/2 ;
            if(nums[mid] == target) return mid;
            if(nums[min] <= nums[mid]){
                if(nums[min] <= target && nums[mid] > target) {
                    max = mid -1;
                } else {
                    min = mid +1;
                }
            }else {
                if(target <= nums[max] && target > nums[mid]) {
                    min = mid +1 ;
                } else {
                    max = mid -1;
                }
            }
        }
        return -1;
    }   
};