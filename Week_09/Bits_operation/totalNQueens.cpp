// leetcode : 52. N皇后 II
class Solution {
private:
    int count,size;
public:
    int totalNQueens(int n) {
        count = 0;
        size = (1 << n) - 1;
        dfs(n,0,0,0,0);
        return count;
    }
    void dfs(int n,int row,int col,int pie,int na) {
        if(row >= n) {count++;return;}
        int bits = (~(col | pie | na)) & size;
        for(int i{0};i<n;++i) {
            int p = (1<<i) & size;
            if((bits & p) != 0) dfs(n,row+1,col | p,(pie | p) << 1,(na | p) >> 1);
        }
    }
};