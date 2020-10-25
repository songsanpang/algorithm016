//这道题最后做的，没精力对照题解改进了，下周刷第二轮得时候改进

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //初始化当前位置与最大距离
        int curx{0},cury{0},dist{0};
        
        //定义方向
        int direx[] {0,1,0,-1};
        int direy[] {1,0,-1,0};
        int curdire{0};
        
        //输入参数处理
        set<pair<int,int>> obstacleSet;
        for(auto i : obstacles) obstacleSet.insert(pair(i[0],i[1]));
        int comLen = commands.size();

        for(int i = 0 ;i< comLen;++i) {
            if(commands[i] == -1) curdire = (curdire+1) % 4;
            else if (commands[i] == -2) curdire = (curdire+3) % 4;
            else if (commands[i] >=1 && commands[i] <=9) {
                for(int j = 0 ;j<commands[i] ; ++j) {
                    int nx = curx + direx[curdire];
                    int ny = cury + direy[curdire];
                    if(obstacleSet.find(pair(nx,ny)) == obstacleSet.end()) {
                        curx = nx,cury = ny;
                        dist = max(dist , curx*curx+cury*cury);
                    }
                    else break;
                }
            }
        }
        return dist;
    }
};
