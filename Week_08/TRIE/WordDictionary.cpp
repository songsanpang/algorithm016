// leetcode:No.211 添加与搜索单词 - 数据结构设计
class WordDictionary {
    bool isEnd;
    vector<WordDictionary*> next;
public:
    /** Initialize your data structure here. */
    WordDictionary() : isEnd(false){
        next.resize(26,nullptr);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* cur = this;
        for(char ch : word) {
            if(cur->next[ch - 'a'] == nullptr) cur->next[ch - 'a'] = new WordDictionary;
            cur = cur->next[ch - 'a'];
        }
        cur -> isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return wordSearch(this,word);
    }
private:
    bool wordSearch(WordDictionary* node,string word) {
        if(word.size() == 1){//递归终止条件
            if(isalpha(word[0])) {
                if(node -> next[word[0] - 'a'] &&  node -> next[word[0] - 'a'] -> isEnd ) return true;
                else return false;
            } 
            for(int i{0} ; i<26 ;++i) if(node -> next[i] &&  node -> next[i] -> isEnd ) return true;
            return false;
        }
        //小写字母情况
        if(isalpha(word[0])) {
            if(node -> next[word[0] - 'a']) return wordSearch(node -> next[word[0] - 'a'],word.substr(1,word.size()-1));
            else return false;
        }
        //. 符号情况,有一种为true 便返回true
        for(int i{0} ; i<26 ;++i) if(node -> next[i]) if(wordSearch(node -> next[i],word.substr(1,word.size()-1))) return true;
        //不存在情况
        return false;
    }
};

