// leetcode : 36. 有效的数独
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<int> row(9,0),col(9,0),block(9,0);
//         for(int i{0};i<9;++i) {
//             for(int j{0};j<9;++j) {
//                 if(board[i][j] == '.') continue;
//                 int num = board[i][j] - '1';
//                 int blocksort = (i/3)*3 + j/3;
//                 if((row[i] & (1<<num)) != 0 || (col[j] & (1<<num)) != 0 || (block[blocksort] & (1<<num)) != 0) return false;//位运算一定要小心优先级问题
//                 row[i] = row[i] | (1 << num);
//                 col[j] = col[j] | (1 << num);
//                 block[blocksort] = block[blocksort] | (1 << num);
//             }
//         }
//         return true;
//     }
// };
