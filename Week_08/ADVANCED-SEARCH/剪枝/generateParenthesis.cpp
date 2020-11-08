//leetcode:No.22. 括号生成
class Solution {
public:
    void dfs(vector<string> &res,string s,int left,int right,int n) {
        if(left == n && n == right) {res.push_back(s);return;}
        if(left<n) dfs(res,s + "(",left +1,right,n);
        if(right<left) dfs(res,s + ")",left ,right+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(!n) return res;
        dfs(res,"",0,0,n);
        return res;
    }
};