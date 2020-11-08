//leetcode:面试题 08.02. 迷路的机器人
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 判断边界条件
        vector<vector<int>> res;
        int row = obstacleGrid.size();
        if(!row) return res;
        int col = obstacleGrid[0].size();
        if(!col) return res;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row -1][col -1] == 1) return res;
        // 初始化边界条件
        int dp[row][col];memset(dp,0,sizeof(dp));
        dp[row-1][col-1] = 1;
        for(int i{row-2} ; i>=0;i--) {//初始化最后一列
            if(obstacleGrid[i][col-1] == 1) dp[i][col-1] = 0;
            else dp[i][col-1] = dp[i+1][col-1];
        }
        for(int i{col-2};i>=0;i--) {//初始化最后一行
            if(obstacleGrid[row-1][i] == 1) dp[row-1][i] = 0;
            else dp[row-1][i] = dp[row-1][i+1];
        }
        //求路径
        for(int i{row-2};i>=0;--i) {
            for(int j{col-2}; j>=0 ;--j) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        if(dp[0][0] == 0) return res;
        int r{0},c{0};
        while(r != row-1 || c != col-1) {
            res.push_back({r,c});
            int down{0};//内部变量不会默认初始化C++，一定要小心
            if(r < row-1) down = dp[r+1][c];
            int right{0};
            if(c < col-1) right = dp[r][c+1];
            if(down >= right) r++;
            else c++;
        }
        res.push_back({row-1,col-1});
        return res;
    }
};
