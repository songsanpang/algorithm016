// class Solution {
// public:
//     struct Treenode {
//         Treenode*le
//     }
//     vector<vector<int>> combine(int n, int k) {

//     }
// };
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void traceback(int n, int k ,int startIndex) {
        if (tmp.size() == k) {
            result.push_back(tmp);
            return ;
        }
        for(int i = startIndex ; i<= n-(k-tmp.size())+1 ;++i){
            tmp.push_back(i);
            traceback(n,k,i+1);
            tmp.pop_back();//回溯关键
        }
        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        traceback(n,k,1);
        return result;
    }
};