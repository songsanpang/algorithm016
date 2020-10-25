// dfs
class Solution {
public:
    int d_x[8] {0,1,1,1,0,-1,-1,-1};
    int d_y[8] {1,1,0,-1,-1,-1,0,1};
    void dfs(int x, int y ,vector<vector<char>>& click) {//传入的是引用，不要忘记检查
        int cnt {0};//数雷
        int x_new,y_new;
        for (int i{0};i < 8;i++) {
            x_new = x + d_x[i];
            y_new = y + d_y[i];
            if(x_new<0 || y_new <0 || x_new >click.size()-1 || y_new > click[0].size ()-1 ) continue;
            cnt += click[x_new][y_new] == 'M';
        } 

        if(cnt == 0) {
            click[x][y] = 'B';
            for (int i{0};i<8;i++) {
                x_new = x + d_x[i];
                y_new = y + d_y[i];
                if(x_new<0 || y_new <0 || x_new >click.size()-1 || y_new > click[x_new].size ()-1 || click[x_new][y_new] != 'E') continue;
                dfs(x_new,y_new,click);
            } 
        }
        else {
            click[x][y] = cnt+ '0';
        }          
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {board[click[0]][click[1]] = 'X';return board;}
        dfs(click[0],click[1],board);
        return board;
    }
};















// class Solution {
// public:
//     vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

//     }
// };
// // bfs
// class Solution {
// public:
//     const int dx[8] = {0,0,1,1,1,-1,-1,-1};
//     const int dy[8] = {1,-1,-1,0,1,-1,0,1};
//     vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//         if (board[click[0]][click[1]] == 'M') {
//             board[click[0]][click[1]] = 'X';
//             return board;
//         }
//         queue<pair<int, int>> q;
//         q.push({click[0], click[1]});
//         board[click[0]][click[1]] = 'B';
//         int m = board.size();
//         int n = board[0].size();
//         while(!q.empty()) {
//             pair<int, int> front = q.front();
//             q.pop();
//             int mSize = 0;
//             for (int i = 0; i < 8; i++) {
//                 int mNew = front.first + dx[i];
//                 int nNew = front.second + dy[i];
//                 if (mNew >= 0 && mNew < m && nNew >= 0 && nNew < n && board[mNew][nNew] == 'M') {
//                     mSize++;
//                 }
//             }
//             if (mSize == 0) {
//                 for (int i = 0; i < 8; i++) {
//                     int mNew = front.first + dx[i];
//                     int nNew = front.second + dy[i];
//                     if (mNew >= 0 && mNew < m && nNew >= 0 && nNew < n && board[mNew][nNew] == 'E') {
//                         board[mNew][nNew] = 'B';
//                         q.push({mNew, nNew});
//                     }
//                 }
//             }
//             else {
//                 board[front.first][front.second] = '0' + mSize;
//             }
//         }
//         return board;
//     }
// };

