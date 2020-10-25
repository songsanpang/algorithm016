// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         vector<int> cnt(3,0);
//         for(int i = 0 ; i< bills.size();i++) {
//             if (bills[i] == 5) cnt[0]++;
//             if (bills[i] == 10) {cnt[0]--;cnt[1]++;}
//             if (bills[i] == 20) {
//                 if (cnt[1]>0) {cnt[1]--;cnt[0]--;}
//                 else cnt[0]-=3;
//             }
//             if(cnt[0] < 0  ) return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int m5 = 0, m10 = 0;
//         for (int i : bills) {
//             switch(i) {
//                 case 5: {m5 ++; continue;} 
//                 case 10: {m10 ++, m5 --; break;}
//                 case 20: if (m10 > 0) m10 --, m5 --;
//                          else m5 -= 3;
//             }
//             if (m5 < 0) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> map;
        for (int i : bills) {
            if (i == 5) map[5] ++;
            else if (i == 10) {map[10] ++, map[5] --;}
            else if (i == 20 && map[10] > 0) {map[10] --, map[5] --;}
            else map[5] -= 3;  //(i == 20 && map[10] == 0)
            if(map[5] < 0) return false;
        }
        return true;
    }
};
