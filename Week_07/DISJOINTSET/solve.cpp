// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
        
//     }
// };

// // dfs
// class Solution {
// public:
//     int m,n;
//     const int dx[4]{0,0,1,-1};
//     const int dy[4]{1,-1,0,0};
//     void dfs(int x, int y,vector<vector<char>>& board) {
//         if(x<0 || y<0 || x >= n || y >= m || board[x][y] != 'O') return;
//         board[x][y] = '@';
//         for(int i{0};i<4;++i) dfs(x+dx[i],y+dy[i],board);
//     }
//     void solve(vector<vector<char>>& board) {
//         n = board.size();
//         if(!n) return;
//         m = board[0].size();
//         for(int i{0};i<n;++i) {
//             dfs(i,0,board);
//             dfs(i,m-1,board);
//         }
//         for(int i{0};i<m;++i) {
//             dfs(0,i,board);
//             dfs(n-1,i,board);
//         }
//         for(int i{0};i<n;++i) {
//             for(int j{0};j<m;++j) {
//                 if(board[i][j] == '@') board[i][j] = 'O';
//                 else board[i][j] = 'X';
//             }
//         }
//     }
// };






//bfs
// class Solution {
// public:
//     const int dx[4] = {1, -1, 0, 0};
//     const int dy[4] = {0, 0, 1, -1};

//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         if (n == 0) {
//             return;
//         }
//         int m = board[0].size();
//         queue<pair<int, int>> que;
//         for (int i = 0; i < n; i++) {
//             if (board[i][0] == 'O') {
//                 que.emplace(i, 0);
//             }
//             if (board[i][m - 1] == 'O') {
//                 que.emplace(i, m - 1);
//             }
//         }
//         for (int i = 1; i < m - 1; i++) {
//             if (board[0][i] == 'O') {
//                 que.emplace(0, i);   
//             }
//             if (board[n - 1][i] == 'O') {
//                 que.emplace(n - 1, i);
//             }
//         }
//         while (!que.empty()) {
//             int x = que.front().first, y = que.front().second;
//             que.pop();
//             board[x][y] = 'A';
//             for (int i = 0; i < 4; i++) {
//                 int mx = x + dx[i], my = y + dy[i];
//                 if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
//                     continue;
//                 }
//                 que.emplace(mx, my);
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (board[i][j] == 'A') {
//                     board[i][j] = 'O';
//                 } else if (board[i][j] == 'O') {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };












// disjointset
class DisJointSet {
private: 
    int count;
    vector<int> parent,size;
public:
    DisJointSet(int n):count(n){
        parent.resize(n);
        size.resize(n);
        for(int i{0};i<n;++i) {
            parent[i] =i;
            size[i] =1;
        }
    }

    void unionSet(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        if(size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }

    bool connection(int p ,int q) {
        if(find(p) == find(q)) return true;
        return false;
    }

    int find(int x) {
        while(x != parent[x]) {
            size[parent[x]] -= size[x];
            parent[x] = parent[parent[x]];
        }
        return x;
    }
};

class Solution {
public:
    int m,n;
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = n?board[0].size():0;
        if(!m) return;
        
        DisJointSet target(n*m+1);
        int dummy = n*m;

        auto node = [&](int i,int j) {
            return i*m +j;
        };

        for(int i{0} ;i<n ;++i) {
            for(int j{0} ; j<m ;++j) {
                if(board[i][j] == 'O') continue;
                if(i == 0 || j == 0 || i == n-1 || j == m-1) target.unionSet(node(i,j),dummy);
                else {
                    if (i - 1 > -1 && board[i - 1][j] == 'O')  target.unionSet(node(i, j), node(i - 1, j));
                    if (i + 1 < n && board[i + 1][j] == 'O') target.unionSet(node(i, j), node(i + 1, j));
                    if (j - 1 > -1 && board[i][j - 1] == 'O')  target.unionSet(node(i, j), node(i, j - 1));
                    if (j + 1 < m && board[i][j + 1] == 'O') target.unionSet(node(i, j), node(i, j + 1));
                }
            }
        }
        for(int i{0} ; i< n ;++i ) {
            for(int j{0} ; j< m ;++j) if(board[i][j] == 'O' && target.connection(node(i,j),dummy)) board[i][j] = 'X';
        }
    }
};

