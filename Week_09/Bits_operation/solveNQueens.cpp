// leetcode : No.51. N 皇后
// class Solution {
// public:
//     void backtrace(vector<vector<string>>& result,vector<string>& board,int raw,int n) {
//         if(raw == n) {result.push_back(board);return;}// if后面只能跟一个语句或者语句块！！！切记切记有两个；一定要加{}
//         // if(raw == n) result.push_back(board);return; 
//         for(int col{0};col<n;++col){
//             if(!isavilable(board,raw,col,n)) continue;
//             board[raw][col] = 'Q';
//             backtrace(result,board,raw+1,n);
//             board[raw][col] = '.';
//         }
//     }

//     bool isavilable (vector<string>& board,int raw,int col,int n) const {
//         for(int i{0};i < raw;++i) if(board[i][col] == 'Q') return false;//判断上方
//         for(int i = raw-1,j = col-1; i>=0 && j>=0 ;i--,j--) if(board[i][j] == 'Q') return false;//判断左上方
//         for(int i = raw-1,j = col+1; i>=0 && j< n ;i--,j++) if(board[i][j] == 'Q') return false;//判断右上方
//         return true;
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string> > result;
//         vector<string> board(n,string(n,'.'));
//         backtrace(result,board,0,n);
//         return result;
//     }
// };


// class Solution {  //c++和python不一样， 用保存列撇拉的方法感觉可读性更差 
// public:
//     bool isValid(int row,int col,vector<int>& exist_p,vector<int>& exist_c,vector<int>& exist_n) {
//         for(int i{0};i<exist_c.size();++i) if(col == exist_c[i] || row +col == exist_n[i] || row - col == exist_p[i]) return false;
//         return true;
//     }

//     void backtrace(vector<vector<string>>& res,vector<string>& board,vector<int>& exist_p,vector<int>& exist_c,vector<int>& exist_n,int row,int n) {
//         if(n == row) {res.push_back(board);return;}
//         for(int i{0};i<n;++i) {
//             if(!isValid(row,i,exist_p,exist_c,exist_n)) continue;
//             board[row][i] = 'Q';
//             exist_p.push_back(row - i);
//             exist_c.push_back(i);
//             exist_n.push_back(row + i);
//             backtrace(res,board,exist_p,exist_c,exist_n,row+1,n);
//             exist_p.pop_back();
//             exist_c.pop_back();
//             exist_n.pop_back();
//             board[row][i] = '.';
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> res;
//         if(!n) return res;
//         vector<string> board(n,string(n,'.'));
//         vector<int> exist_p,exist_c,exist_n;
//         backtrace(res,board,exist_p,exist_c,exist_n,0,n);
//         return res;
//     }
// };

// finally！到了位运算方法了
class Solution {
private:
    vector<vector<string>> res;
    vector<string> tmp;
    int size;
public:
    void dfs(int n,int row,int col,int pie,int na) {
        if(row >= n) {res.push_back(tmp);return;}
        int bits = (~(col | pie | na)) & size;
        for(int i{0};i<n;++i) {
            int p = (1 << i) & size;
            if((bits & p) == 0) continue;
            tmp[row][i] = 'Q';
            dfs(n,row+1,col | p,(pie | p) << 1,(na | p) >> 1);
            tmp[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        tmp.resize(n,string(n,'.'));
        size = (1<<n) -1;
        dfs(n,0,0,0,0);
        return res;
    }
};