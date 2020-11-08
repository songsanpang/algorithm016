// leetcode : 127. 单词接龙

// // BFS
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> word(wordList.begin(),wordList.end());//提醒自己c++多多使用构造函数
//         if(word.find(endWord) == word.end()) return 0;
//         int step{1};
//         queue<string> qu;
//         unordered_set<string> visited;
//         qu.push(beginWord);visited.insert(beginWord);
//         while(!qu.empty()) {
//             int size = qu.size();
//             while(size--) {
//                 string curWord = qu.front(); qu.pop();
//                 for(int i{0} ; i< curWord.size() ;++i) {
//                     char tmp = curWord[i];
//                     for(int j{0}; j<26 ;++j) {
//                         curWord[i] = j + 'a';
//                         if(curWord[i] == tmp) continue;
//                         if(curWord == endWord) return step + 1;
//                         if(word.find(curWord) != word.end() && visited.find(curWord) == visited.end()) {
//                             qu.push(curWord); visited.insert(curWord);
//                         }
//                     }
//                     curWord[i] = tmp;
//                 }
//             }
//             ++step;
//         }
//         return 0;
//     }
// };



//  双向BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(),wordList.end());
        if(word.find(endWord) == word.end()) return 0;//判断边界条件
        unordered_set<string> beginSet,endSet;//定义及初始化set和qu
        queue<string> beginQ,endQ;
        beginSet.insert(beginWord);beginQ.push(beginWord);
        endSet.insert(endWord);endQ.push(endWord);
        int step {1};//初始化步长
        while((!beginQ.empty()) && (!endQ.empty())) {
            if(beginQ.size() > endQ.size()) {beginQ.swap(endQ);beginSet.swap(endSet);}
            int n = beginQ.size();
            while( n-- ) {
                string curWord = beginQ.front(); beginQ.pop();
                for(int i{0};i<curWord.size(); ++i) {
                    char tmp = curWord[i];
                    for(int j{0} ; j<26 ;++j) {
                        curWord[i] = j + 'a';
                        if(beginSet.find(curWord) != beginSet.end()) continue;
                        if(endSet.find(curWord) != endSet.end()) return step + 1;
                        if(word.find(curWord) != word.end()) {beginQ.push(curWord);beginSet.insert(curWord);};
                    }
                    curWord[i] = tmp;
                }
            }
            step++;
        }
        return 0;
    }
};

                