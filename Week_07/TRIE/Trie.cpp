class Trie {
private:
    bool isEnd = false;
    Trie * next[26];
public:
    /** Initialize your data structure here. */
    Trie() : isEnd(false),next{nullptr}{
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char ch : word) {
            if(node -> next[ch - 'a'] == nullptr) {
                node->next[ch - 'a'] = new Trie();
                node = node->next[ch - 'a'];
            } else node = node->next[ch - 'a'];
        } 
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) const {
        const Trie *node = this;
        for(char ch : word) {
            node = node->next[ch - 'a'];
            if(node == nullptr) return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char ch : prefix) {
            node = node->next[ch - 'a'];
            if(node == nullptr) return false;
        }
        return true;
    }
};
