// leetcode : 37. 解数独
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    bool isValid(int x,int y,char c ,const vector<vector<char>>& board) {
        for(int i{0};i<9;++i) if(board[i][y] == c) return false;
        for(int i{0};i<9;++i) if(board[x][i] == c) return false;
        int bx = (x/3)*3,by = (y/3)*3;
        for(int i{bx};i<bx+3;++i) {
            for(int j{by};j<by+3;++j) {
                if(board[i][j] == c) return false;
            }
        }
        return true ;
    }

    bool dfs (vector<vector<char>>& board) {
        for(int x{0};x<board.size();++x) {
            for(int y{0};y<board[0].size();y++) {
                if(board[x][y] != '.') continue;
                for(char c{'1'};c<='9';++c) {
                    if(isValid(x,y,c,board)) {
                        board[x][y] = c;
                        if(dfs(board)) return true;
                        board[x][y] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
};