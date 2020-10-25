class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,int> m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
        for(char c : s) {
            int ci =m[c];
            if(ci>0 && ci<4) st.push(c);
            if (ci>3 && ci<7) {
                if (!st.empty() && ci == m[st.top()] + 3 ) {
                    st.pop();
                    continue;
                } 
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};






