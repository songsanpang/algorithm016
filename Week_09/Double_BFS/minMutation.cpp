// leetcode : 433. 最小基因变化
// // BFS
// class Solution {
// public:
//     int minMutation(string start, string end, vector<string>& bank) {
//         unordered_set<string> gene(bank.begin(),bank.end()),visited;
//         if(gene.empty() || gene.find(end) == gene.end()) return -1;
//         vector<char> store {'A','C','G','T'};
//         queue<string> qu;
//         qu.push(start);visited.insert(end);
//         int step{0};
//         while(!qu.empty()) {
//             step++;
//             int size = qu.size();
//             while(size--) {
//                 string curgene = qu.front();
//                 qu.pop();
//                 for(int i{0};i<8;++i) {
//                     char tmp = curgene[i];
//                     for(char c : store) {
//                         if(c==tmp) continue;
//                         curgene[i] = c;
//                         if(curgene == end) return step;
//                         if(gene.find(curgene) != gene.end()
//                             && visited.find(curgene) == visited.end()) {
//                                 qu.push(curgene);
//                                 visited.insert(curgene);
//                             }
//                     }
//                     curgene[i] = tmp;
//                 }
//             }
//         }
//         return -1;
//     }
// };

//双向BFS
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> gene(bank.begin(),bank.end());//边界条件判断
        if(gene.empty() || gene.find(end) == gene.end()) return -1;
        unordered_set<string> beginSet,endSet;//初始化双向set和queue
        queue<string> beginQ,endQ;
        beginSet.insert(start);beginQ.push(start);
        endSet.insert(end);endQ.push(end);
        vector<char> store{'A','C','G','T'};
        int step{0};
        while((!beginQ.empty()) && (!endQ.empty())) {
            step ++;
            if(beginQ.size() > endQ.size()) {beginQ.swap(endQ);beginSet.swap(endSet);}
            int size = beginQ.size();
            while(size --) {
                string curgene = beginQ.front();beginQ.pop();
                for(int i{0};i<8;++i) {
                    char tmp = curgene[i];
                    for(char c : store) {
                        if(c == tmp) continue;
                        curgene[i] = c;
                        if(beginSet.find(curgene) != beginSet.end()) continue;
                        if(endSet.find(curgene) != endSet.end()) return step;
                        if(gene.find(curgene) != gene.end()) {beginQ.push(curgene);beginSet.insert(curgene);}
                    }
                    curgene[i] = tmp;
                }
            }
        }
        return -1;
    }
};
