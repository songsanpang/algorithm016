//leetcode No.990
class disjointSet {
private: 
    int count;
    vector<int> parent,size;
    int find(int x) {
        while(x != parent[x]) {
            size[parent[x]] -= size[x];
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    disjointSet(int n):count(n) {
        parent.resize(n);
        size.resize(n);
        for(int i{0};i<n;++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void unionSet(int p,int q) {
        int rootQ = find(q);
        int rootP = find(p);
        if(rootP == rootQ) return;
        if(size[rootQ] < size[rootP]) {
            size[rootP] += size[rootQ];
            parent[rootQ] = rootP;
        }else {
            size[rootQ] += size[rootP];
            parent[rootP] = rootQ;
        }
        count--;
    }
    
    bool connection (int p ,int q){
        int rootQ = find(q);
        int rootP = find(p);
        if(rootP == rootQ) return true;
        return false;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        disjointSet target(26);
        for(string word : equations) {
            if(word[1] == '=') target.unionSet(word[0]-'a',word[3]-'a');
        }
        for(string word : equations) {// 检查不等关系是否打破相等关系的连通性
            if(word[1] == '!' && target.connection(word[0]-'a',word[3]-'a')) return false; 
        }
        return true;
    }
};
