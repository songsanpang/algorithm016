// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;//很酷，之前没想到可以这么用
        for(string str : strs) {
            string t = str;
            sort(t.begin(),t.end());
            m[t].push_back(str);
        }
        for(auto& str_v : m) {
            res.push_back(str_v.second);
        }
        return res;
    }
};



			

