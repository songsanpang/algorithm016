// // hashmap
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;
//         unordered_map<char,int> cnt;
//         for(char ch : s) cnt[ch]++;
//         for(char ch : t) if(--cnt[ch] == -1) return false;
//         return true;  
//     }
// };

// 数组法, 本质也是hash，用数组更快O（1）的查询更改
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int map[26]{0};
        for(char ch : s) map[ch -'a']++;
        for(char ch : t) if(--map[ch - 'a'] == -1) return false;
        return true;
    }
};