// //  暴力法
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         for(int i =0;i< nums.size()-2;i++) {
//             for(int j=i+1;j<nums.size()-1;j++) {
//                 for(int k=j+1;k<nums.size();k++) {
//                     if(nums[i] + nums[j] +nums[k] == 0) {
//                         int z = 0;
//                         for(vector<int> set : result){
//                             auto ret_i = std::find(set.begin(),set.end(),nums[i]);
//                             auto ret_j = std::find(set.begin(),set.end(),nums[j]);
//                             auto ret_k = std::find(set.begin(),set.end(),nums[k]);
//                             if(ret_i != set.end() & ret_j != set.end() & ret_k != set.end()) {
//                                 z = -1;
//                                 break;
//                             }
//                         }
//                         if(z == 0) {
//                             vector<int> sub_result;
//                             sub_result.push_back(nums[i]);
//                             sub_result.push_back(nums[j]);
//                             sub_result.push_back(nums[k]);
//                             result.push_back(sub_result);
//                         }
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };














//双指针法 参考题解里面的代码改的，之前速度超级慢
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int N = nums.size();
        for(int i= 0;i<N-2;++i) {
            if(nums[i] >0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=N-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum>0) --k;
                else if (sum<0)  ++j;
                else {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[++j]);
                    while(j<k && nums[k]==nums[--k]);
                }
            }
        }
        return result;
    }
};
















// //题解里面大神的解法
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int N = nums.size();//这里减少了后面多次求size（）的时间
//         vector<vector<int> > res;
//         for (int i = 0; i < N - 2; ++i) {
//             if (nums[i] > 0) break;
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
//             int l = i + 1;
//             int r = N - 1;
//             while (l < r) {
//                 int s = nums[i] + nums[l] + nums[r];
//                 if (s > 0) {
//                     --r;
//                 } else if (s < 0) {
//                     ++l;
//                 } else {
//                     res.push_back({nums[i], nums[l], nums[r]});
//                     while (l < r && nums[l] == nums[++l]);
//                     while (l < r && nums[r] == nums[--r]);
//                 }
//             }
//         }
//         return res;
//     }
// };






