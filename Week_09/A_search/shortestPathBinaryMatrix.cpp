// leetcode : 1091. 二进制矩阵中的最短路径
// // bfs
// class Solution {
// private:
//     vector<int> dx{0,0,1,1,1,-1,-1,-1};
//     vector<int> dy{1,-1,1,0,-1,1,0,-1};
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();// jiancha边界条件
//         if(n == 0 || grid[0][0] || grid[n-1][n-1]) return-1;
//         if(n<=2) return n;
//         queue<pair<int,int>>qu;
//         qu.push(make_pair(0,0));
//         int step = 1;
//         grid[0][0] = 2;
//         while(!qu.empty()) {
//             int size = qu.size();
//             while(size--) {
//                 int curx = qu.front().first,cury = qu.front().second;
//                 qu.pop();
//                 for(int i{0};i<8;++i) {
//                     int newx = curx + dx[i];
//                     int newy = cury + dy[i];
//                     if(newx == n-1 && newy == n-1) return step+1;
//                     if(newx < 0 || newx >= n || newy < 0 || newy >= n || grid[newx][newy]) continue;
//                     qu.push(make_pair(newx,newy));
//                     grid[newx][newy] = 2;
//                 }
//             }
//             step++;
//         }
//         return -1;
//     }
// };


// // A*

int n,m;
// 记录（x，y）位置处最小距离是多少
struct pos {
    int x,y,dis;
    pos (int x, int y, int dis) : x(x), y(y), dis(dis){}
};
// 关键：由于对角线移动 比 水平、垂直移动的距离更远而花费一样，所以以如下方法排序优先级；
// 例如：（0,0） -> （2,5）的最优预期花费就是max(2 - 0, 5 - 0)
bool operator< (const pos A, const pos B) {
    return max(n - 1 - A.x, m - 1 - A.y) + A.dis - (max(n - 1 - B.x, m - 1 - B.y) + B.dis) >= 0;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;
        n = grid.size();
        m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        if (n == 1 && m == 1) return 1;
        priority_queue<pos> q;
        pos start(0, 0, 1);
        q.push(start);
        // 拥塞路径加入closeList
        vector<bool> closeList(n * m, false);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 1) closeList[i * m + j] = true;
        // 不需要记录父节点，故openList只保存最小花费
        vector<int> openList(n * m, 0);
        openList[0] = 1;
        // 八个移动方向
        vector<vector<int>> mov {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            pos cur = q.top();
            q.pop();
            int curIdx = cur.x * m + cur.y;
            closeList[curIdx] = true;
            for (int k = 0; k < 8; ++k) {
                int xx = cur.x + mov[k][0];
                int yy = cur.y + mov[k][1];
                int nextIdx = xx * m + yy;
                if (0 <= xx && xx < n && 0 <= yy && yy < m && !closeList[nextIdx]) {
                    if (xx == n - 1 && yy == m - 1) return openList[curIdx] + 1;
                    // 没有到走过改点或者当前的路线更优
                    if (openList[nextIdx] == 0 || openList[nextIdx] > openList[curIdx] + 1) {
                        openList[nextIdx] = openList[curIdx] + 1;
                        pos next(xx, yy, openList[curIdx] + 1);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
