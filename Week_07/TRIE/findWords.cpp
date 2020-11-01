class TrieNode {
public:
    string word;
    vector<TrieNode*> nodes;
    TrieNode():nodes(26,nullptr){}
};

class Solution {
        int cols,rows;
        vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows? board[0].size() : 0;
        if(rows == 0 || cols == 0) return res;
        //建tries
        TrieNode *root = new TrieNode();
        for(string word : words) {
            TrieNode *cur = root;
            for(int i{0};i<word.size();++i) {
                int index = word[i] - 'a';
                if(cur->nodes[index] == nullptr) cur->nodes[index] = new TrieNode();
                cur = cur->nodes[index];
            }
            cur->word = word;
        }
        //遍历调用dfs
        for(int i{0}; i<rows ;++i) {
            for(int j{0}; j<cols;++j) {
                dfs(board,i,j,root);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int row, int col,TrieNode* cur) {
        char ch = board[row][col];
        if(ch == '.' || cur->nodes[ch - 'a'] == nullptr ) return;//递归终止条件//要先判断ch == '.'，不然nodes[ch - 'a']会越界，不好检查这种错误，但这也是c++短路执行优势，会更快，也方便写一些这种奇怪得情况
        cur = cur->nodes[ch - 'a'];
        if(cur -> word != "") {
            res.push_back(cur->word);
            cur -> word = "";
        }
        board[row][col] = '.';
        if(row>0) dfs(board,row-1,col,cur);
        if(col>0) dfs(board,row,col-1,cur);
        if(row+1<rows) dfs(board,row+1,col,cur);
        if(col+1<cols) dfs(board,row,col+1,cur);
        board[row][col] = ch;
    }
};