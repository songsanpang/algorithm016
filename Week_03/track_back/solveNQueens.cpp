class Solution {
public:
    void back_trace(int n,int raw,vector<string>& board,vector<vector<string>>& result) {
        if (raw == n) {
            result.push_back(board);
            return ; 
        }
        for(int col = 0;col < n; col++){
            if(!isValid(raw,col,board,n)) continue;
            board[raw][col] = 'Q';
            back_trace(n,raw+1,board,result);
            board[raw][col] = '.';
        }
    }
    bool isValid(int raw,int col,vector<string>& board,int n) {
        for(int i= 0;i<raw ;++i) {
            if(board[i][col] == 'Q') return false;
        }
        for(int i = raw ,j= col ;i>=0 && j >= 0; --i,--j) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = raw ,j= col ;i>=0 && j < n; --i,++j) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        back_trace(n,0,board,result);
        return result;
    }
};