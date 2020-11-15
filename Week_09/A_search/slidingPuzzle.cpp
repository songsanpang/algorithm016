// leetcode : 773. 滑动谜题

//标准的bfs
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string end = "123450";
        string begin = "";//初始化并转化为开始字符串
        int row{2},col{3};
        for(int i{0};i<row;++i) {
            for(int j{0};j<col;++j) {
                begin += board[i][j] +'0';
            }
        }
        if(begin == end) return 0;
        vector<vector<int>> neighbor{{1,3},{0,2,4},{1,5},{0,4},{3,1,5},{4,2}};//创建邻接表
        queue<string> qu;qu.push(begin);
        unordered_set<string> visited;visited.insert(begin);
        int step{0};
        while(!qu.empty()) {
            int size = qu.size();step++;
            while(size --) {
                string tmp = qu.front();qu.pop();
                int index{0};
                for(;tmp[index] != '0';index++) ;
                for(int i : neighbor[index]) {
                    string new_board = tmp;
                    swap(new_board[i],new_board[index]);
                    if(new_board == end) return step;
                    if(!visited.count(new_board)) {qu.push(new_board);visited.insert(new_board);}
                }
            }
        }
        return -1;
    }
};



// // A*
// class Solution {
// public:
//     static const int N = 50000;
//     int pow_6[7];
//     int dist[N];
// public:
//     vector<int> get_moves(int state)
//     {
//         int idx_0 = 0, tmp_state = state;
//         vector<int> res;
//         while(tmp_state)
//         {
//             if(tmp_state % 6 == 0) break;
//             tmp_state /= 6;
//             idx_0 ++;
//         }
//         if(idx_0 != 2 && idx_0 != 5)
//         {
//             int num_minus_1 = (state / pow_6[idx_0 + 1]) % 6;
//             // cout << "left: " << num_minus_1 << endl;
//             res.push_back(state - num_minus_1 * pow_6[idx_0 + 1] + num_minus_1 * pow_6[idx_0]);
//         }
//         if(idx_0 != 3 && idx_0 != 0)
//         {
//             int num_plus_1 = (state / pow_6[idx_0 - 1]) % 6;
//             // cout << "right: " << num_plus_1 << endl;
//             res.push_back(state - num_plus_1 * pow_6[idx_0 - 1] + num_plus_1 * pow_6[idx_0]);
//         }
//         if(idx_0 + 3 < 6)
//         {
//             int num_minus_3 = (state / pow_6[idx_0 + 3]) % 6;
//             // cout << "up: " << num_minus_3 << endl;
//             res.push_back(state - num_minus_3 * pow_6[idx_0 + 3] + num_minus_3 * pow_6[idx_0]);
//         }
//         if(idx_0 - 3 >= 0)
//         {
//             int num_plus_3 = (state / pow_6[idx_0 - 3]) % 6;
//             // cout << "down: " << num_plus_3 << endl;
//             res.push_back(state - num_plus_3 * pow_6[idx_0 - 3]  + num_plus_3 * pow_6[idx_0]);
//         }
//         return res;
//     }
//     int slidingPuzzle(vector<vector<int>>& board) {
//         memset(dist, -1, sizeof dist);
//         int start = 0, end = 0, p = 1;
//         for(int i = 0; i <= 6; i++)
//             pow_6[i] = p, p *= 6;
//         p = 1;
//         for(int i = 1; i >= 0; i--)
//             for(int j = 2; j >= 0; j--)
//             {
//                 start +=  board[i][j] * p;
//                 p = p * 6;
//             }
//         p = 6;
//         for(int i = 5; i >= 1; i--)
//         {
//             end += p * i;
//             p = p * 6;
//         }
//         if(start == end) return 0;
//         return a_star(start, end);
//     }
//     int a_star(int start, int end)
//     {
//         // dist, state
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
//         heap.push({f_distance(start), start});
//         dist[start] = 0;
//         while(heap.size())
//         {
//             auto t = heap.top();
//             heap.pop();
//             int state = t.second;
//             if(state == end) return dist[state];
//             vector<int> moves = get_moves(state);
//             for(int m:moves)
//             {
//                 if(dist[m] == -1 || dist[m] > dist[state] + 1)
//                 {
//                     dist[m] = dist[state] + 1;
//                     heap.push({dist[m] + f_distance(m), m});
//                 }
//             }
//         }
//         return -1;
//     }
//     // 估价函数：与终点的曼哈顿距离
//     int f_distance(int state)
//     {
//         state /= 6;
//         int res = 0, cur_num = 5;
//         // 六进制表示每一位的距离
//         while(state)
//         {
//             res += abs(state % 6 - cur_num);
//             cur_num --;
//             state /= 6;
//         }
//         return res;
//     }
// };

