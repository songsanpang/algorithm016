// dfs
// class Solution {
// public:
//     void dfs(int i, int j ,vector<vector<char>>& grid) {
//         if(grid[i][j] == '0') return;
//         grid[i][j] = '0';
//         if(i>0 ) dfs(i-1,j,grid);
//         if(j>0) dfs(i,j-1,grid);
//         if(i<grid.size()-1) dfs(i+1,j,grid);
//         if(j<grid[0].size()-1) dfs(i,j+1,grid);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int cnt{0};
//         for(int i{0}; i< grid.size() ;++i) {
//             for(int j{0} ; j< grid[0].size() ;++j) {
//                 if(grid[i][j] == '0') continue;
//                 dfs(i,j,grid);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

// // disjointset  自己写的版本，怎么搞都会超出时间限制
// class DisjointSet {
// private:
//     // vector<int> parent;
//     int *parent;
//     // vector<int> size;
//     int count;
// public:
//     DisjointSet(int n) : count(n) {
//         // size.resize(n,1);
//         // parent.resize(n);
//         memset(parent,0,n);
//         for(int i{0};i<n;++i) parent[i] = i;
//     }

//     int find(int x) {
//         while(parent[x] != x) {
//             // size[parent[x]] -= size[x];
//             parent[x] = parent[parent[x]];
//         }
//         return x;
//     }
//     void unionSet(int p ,int q) {
//         int rootQ = find(q);
//         int rootP = find(p);
//         if(rootP == rootQ) return;
//         // if(size[rootP] < size[rootQ]){
//         parent[rootP] = rootQ;
//             // size[rootQ] += size[rootP];
//         // } else {
//             // parent[rootQ] = rootP;
//             // size[rootP] += size[rootQ];
//         // }
//         count--;
//     }
//     int search() {
//         return count;
//     }
// };
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int row = grid.size();
//         if (!row) return  0;
//         int col = grid[0].size();
//         int ans = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++){
//                 if (grid[i][j] == '0') ans++;
//             }
//         }
//         DisjointSet target(row*col);
//         for (int i = 0 ; i < row ; i++){
//             for ( int j = 0; j < col ; j++){
//                 if ( i > 0 && grid[i][j] == '1' && grid[i-1][j] == '1'){
//                     target.unionSet(i*col +j, (i-1)*col+j);
//                 }
//                 if ( j > 0 && grid[i][j] == '1' && grid[i][j-1] == '1'){
//                     target.unionSet(i*col +j, i*col+j-1);
//                 }
//             }
//         }
//         return target.search() - ans;
//     }
// };



// 参考题解的版本，感觉和自己写的差不多，但不会超时
struct DSU{
    vector<int> data;

    void makeSet(int n){
        data.resize(n);
        for (int i = 0; i < n; i++) data[i] = i;
    };

    bool unionSet(int i, int j){
        int p1 = parent(i);
        int p2 = parent(j);
        if ( p1 != p2 ){
            data[p1] = p2;
        } 
        return p1 != p2;

    };

    int parent(int i){
        int root = i;
        while ( data[root] != root){
            root = data[root];
        }
        return root;

    };
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 ) return  0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1') ans++;
            }
        }
        DSU dsu;
        dsu.makeSet( m * n);
        for (int i = 0 ; i < m ; i++){
            for ( int j = 0; j < n ; j++){
                if ( i > 0 && grid[i][j] == '1' && grid[i-1][j] == '1'){
                    ans -= dsu.unionSet(i*n +j, (i-1)*n+j);
                }
                if ( j > 0 && grid[i][j] == '1' && grid[i][j-1] == '1'){
                    ans -= dsu.unionSet(i*n +j, i*n+j-1);
                }

            }
        }
        return ans;

    }
};