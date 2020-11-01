class DisJointSet {//关键： 变量：连通分量，父亲数组，重量数组；函数：构造,union,find,connect,count record,
private:
    int count;//连通分量
    vector<int> parent;//存储树
    vector<int> size;//存储树大小
public:
    DisJointSet(int n):count(n) {
        for(int i{0};i<n;++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void unionSet(int p,int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        if(size[rootP < rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }

    bool connected(int p,int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int countrecord() {return count;}

private:
    int find(int x) {
        while (parent[x] != x){
            size[parent[x]] -= size[x];
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(!n) return 0;
        DisJointSet target(n);
        for(int i{0};i<n;++i) {
            for(int j{0};j<i;j++) if(M[i][j] == 1) target.unionSet(i,j);
        }
        return target.countrecord();
    }
};
