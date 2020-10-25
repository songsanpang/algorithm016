// //暴力法
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         for(int i =0; i< nums.size()-1;++i) {
//             for(int j =i+1;j < nums.size(); ++j ) {
//                 if(nums[i]==0){
//                     if(nums[j]==0) continue;
//                     else {
//                         int z = nums[i];
//                         nums[i] = nums[j];
//                         nums[j] = z;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// };

// //双指针法
// class Solution {
//     public:
//     void moveZeroes(vector<int>& nums) {
//         int j=-1;
//         for(int i=0 ;i<nums.size(); ++i) {
//             if(nums[i]==0) {
//                 j = i ;
//                 break;
//             }
//         }
//         if(j == -1) return;
//         for(int i =j; i<nums.size(); ++i) {
//             if(nums[i]!=0) {
//                     nums[j++]=nums[i];
//                     nums[i] = 0;
//                 }
                
//         }
//         return;
//     }
// };

//交换计数法
class  Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i = 0; i < nums.size();++i) {
            if(nums[i] != 0) {
                nums[count++] = nums[i];
            }
        }
        for(int i = count; i < nums.size();++i) {
            nums[i]=0;
        }
    }
};