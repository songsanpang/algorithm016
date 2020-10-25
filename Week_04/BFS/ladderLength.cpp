// class Solution {
// public:
    
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
//     }
// };

// //bfs
// class Solution {
// public:  
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> visible;//准备遍历的set，并导入根节点
//         for(auto i : wordList) visible.insert(i);
//         if(visible.find(endWord) == visible.end()) return 0;
//         queue<pair<string,int> > q;
//         q.push({beginWord,1});

//         string tmp;//准备中间复用变量
//         int step;

//         while(!q.empty()) {
//             tmp = q.front().first; // 取头节点判断是否搜索到目标数据
//             step = q.front().second;
//             q.pop(); 
//             if(tmp == endWord) return step;
            
//             char ch;
//             for(int i=0; i< tmp.size() ; ++i) {
//                 ch = tmp[i];
//                 for(char c = 'a'; c <= 'z';c++) {
//                     if(ch == c) continue;
//                     tmp[i] = c;
//                     if(visible.find(tmp) == visible.end()) continue;
//                     q.push({tmp, step+1});
//                     visible.erase(tmp);
//                 }
//                 tmp[i] = ch;
//             }
//         }
//         return 0;//从begin出发查找不到了返回0
//     }
// };


// 双向bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end()); //初始化
        if(dict.find(endWord) == dict.end()) return 0;
        unordered_set<string> beginSet,endSet,tmp,visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len =2;

        while(!beginSet.empty() && !endSet.empty()){
            if(beginSet.size() > endSet.size()) {
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            for(auto word : beginSet) {
                for(int i =0 ; i< word.size();++i) {
                    char old = word[i];
                    for(char c = 'a' ; c <= 'z' ; c++) {
                        if(old == c ) continue;
                        word[i] = c;
                        if(endSet.find(word)!=endSet.end()) return len;
                        if(dict.find(word) != dict.end() && visited.find(word) == visited.end()) {
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            beginSet = tmp;
            len ++ ;
        }
        return 0;
    }
};
