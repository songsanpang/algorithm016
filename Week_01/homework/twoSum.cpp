//暴力法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size(); 
        vector<int> result{0,0};
        for(int i=0; i<N-1; ++i) {
            for(int j=i+1; j<N; ++j) {
                if(nums[i] + nums[j] == target) {
                    result = {i,j};
                    return result;
                }
            }
        }
        return result;
    }
};

// //双指针法 : 会改变对应数的下标，不可取
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int> result{0,0};
//         int i = 0,j=nums.size()-1;
//         while(i!=j) {
//             if(nums[i] + nums[j] > target) {
//                 --j;
//                 continue;
//             }
//             if(nums[i] + nums[j] == target) {
//                 return result={i,j};
//             }
//             ++i;
//         }
//         return result;
//     }
// };