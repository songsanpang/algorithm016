class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> tmp = triangle;
        int row = tmp.size(),columns;
        for( int i =  row-2 ; i>=0 ;--i) {
            for( int j = 0 ;j< tmp[i].size() ;j++) {
                tmp[i][j] = min(tmp[i+1][j],tmp[i+1][j+1]) + tmp[i][j] ;
            } 
        }
        return tmp[0][0]; 
    }
};