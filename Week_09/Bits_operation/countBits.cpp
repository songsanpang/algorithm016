// leetcode : 338. 比特位计数
// 单纯的位运算
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         if(num <= 0) return {0};
//         vector<int> res;
//         for(int i{0};i<=num;++i) {
//             int count{0},tmp{i};
//             while(tmp) {tmp &= (tmp-1);count++;}
//             res.push_back(count);
//         }
//         return res;
//     }
// };

//超哥给的方法用到了dp的想法，但效率并没有更优...
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> bits(num+1,0);
//         for(int i{1};i<=num;++i) bits[i] += bits[i & (i-1)] +1 ;
//         return bits;
//     }
// };