class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children{0},No{0};
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(children != g.size() && No != s.size()) {
            if(g[children] <= s[No]) children++,No++;
            else No++;
        }
        return children;
    }
};