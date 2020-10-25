 class Solution {
 public
     vectorint maxSlidingWindow(vectorint& nums, int k) {

     }
 };
暴力法
class Solution {
public
    vectorint maxSlidingWindow(vectorint& nums, int k) {
        vectorint res;
        int max;
        for(int i =0;inums.size()-k+1;++i) {
            max = nums[i];
            for(int j =i;ji+k;++j) {
                if(nums[j]max) max = nums[j];
            }
            res.push_back(max);
        }
        return res;
    }
};


 双端队列法-存数组下标
 class Solution {
 public
     vectorint maxSlidingWindow(vectorint& nums, int k) {
         dequeint windows;
         int N = nums.size();
         vectorint result;
         for(int i = 0 ;ik ;++i) {
             while(!windows.empty() && nums[i] nums[windows.back()]) {清理尾部小于新加入值的
                 windows.pop_back();
             }
             windows.push_back(i);
         }
         result.push_back(nums[windows.front()]);
         for(int i = k ;iN ;++i) {
             if(!windows.empty() && windows.front()i-k+1) {清理头部超出范围的
                 windows.pop_front();
             }
             while(!windows.empty() && nums[i] nums[windows.back()]) {清理尾部小于新加入值的
                 windows.pop_back();
             }
             windows.push_back(i);
             result.push_back(nums[windows.front()]);
         }
         return result;
     }
 };