class Solution {
public:
    void dfs(int n,int left,int right,string s ,vector<string>& res ) {
        if(n == left && left == right ) {res.push_back(s);return ;}
        if(left < n)  dfs(n,left+1,right,s+'(',res);
        if(right < left)  dfs(n,left,right+1,s+')',res);
    }
    vector<string> generateParenthesis(int n) {
            vector<string> res;
            dfs(n,0,0,"",res);
            return res;
    }
};