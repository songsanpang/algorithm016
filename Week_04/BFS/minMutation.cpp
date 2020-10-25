//bfs
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //1判断极端情况
        if(start.empty() || end.empty() || bank.empty()) return -1;
        if(find(bank.begin(),bank.end(),end) == bank.end()) return -1;

        //2.bfs初始化工作
        queue<string> qu;
        qu.push(start);
        int step{0};
        vector<int> visited(bank.size(),0);
        
        //3 进行bfs
        while (!qu.empty()) {
            step++;
            string tmp;
            int n = qu.size();
            for(int i =0; i< n ;i++) {
                tmp = qu.front();
                qu.pop();
                for(int j=0 ;j < bank.size();j++){
                    if(visited[j] == 1) continue;
                    int diff = 0;
                    for(int k =0;k < bank[j].size() ;k++ ) {
                        if (bank[j][k] == tmp[k]) continue;
                        diff++;
                    }
                    if(diff != 1) continue;
                    if(bank[j] == end) return step;
                    visited[j] =1;
                    qu.push(bank[j]);
                }
            }
        }
        return -1;
    }
};












