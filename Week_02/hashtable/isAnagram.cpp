// hashmap
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;
//         unordered_map<char,int> map;
//         for(char c : s) map[c]++;
//         for(char c : t) {
//             if(--map[c] == -1) return false;
//         }
//         return true;
//     }
// };

// 数组法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int hash[26]{0};
        for(char c : s) hash[c - 'a']++;
        for(char c : t) {
            if(-- hash[c - 'a'] == -1) return false;
        }
        return true;
    }
};
