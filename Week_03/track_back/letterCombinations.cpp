class Solution {
    const string letterMap[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> result;
    void getCombinations(const string& digits, const string& tmp,int index) {
        if(index == digits.size()) {
            result.push_back(tmp);
            return ;
        }
        int mapindex = digits[index] - '0';
        string stmp =  letterMap[mapindex];
        for(int i=0 ;i< stmp.size() ;++i) {
            getCombinations(digits,tmp+stmp[i],index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return result;
        getCombinations(digits,"",0);
        return result;
    }
};