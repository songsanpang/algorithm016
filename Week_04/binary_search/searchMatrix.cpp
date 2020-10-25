class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 ) return false;
        if(matrix[0].size() ==0 ) return false;
        int row = matrix.size();
        int line = matrix[0].size();
        if(target < matrix[0][0] || target >matrix[row-1][line-1]) return false;
        int tar_row{-1};
        for(int i = 0 ; i< row ; ++i) {
            if(target > matrix[i][line-1]) continue;
            else if(target >= matrix[i][0] ) {
                tar_row = i;
                break;
            } else return false;
        }
        if(tar_row == -1) return false;
        for(int j= 0 ;j< line ; j++) {
            if(matrix[tar_row][j] == target) return true;
        }
        return false;
    }
};

//将二维矩阵拖为一维矩阵，然后就是一个有序的一维数组了，利用二分查找就行
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix,int target){
//         if(matrix.empty()||matrix[0].empty())return 0;
//         int left=0,right=matrix.size()*matrix[0].size()-1;
//         int n=matrix[0].size();
//         while(left<=right)//循环结束的条件为区间内没有元素了
//         {
//             int mid=left+((right-left)>>1);
//             if(matrix[mid/n][mid%n]>target)right=mid-1;
//             else if(matrix[mid/n][mid%n]<target)left=mid+1;
//             else return true;
//         }
//         return false;
//     }
// };