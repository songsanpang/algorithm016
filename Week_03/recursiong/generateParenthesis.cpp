class Solution {
public:
    void bracket(vector<string>& tmp,int cnt,int left ,int right,string s) {
        if(left < cnt) {
            bracket(tmp ,cnt ,left+1,right,s+"(");
        }
        if(right < left) {
            bracket(tmp ,cnt ,left,right+1,s+")");
        }
        if(right == cnt ) tmp.push_back(s);
        return ;       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bracket(res,n,0,0,"");
        return res;
    }
};