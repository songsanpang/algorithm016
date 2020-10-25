class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size()-1;
        for(int i =digits.size()-1; i>=0; --i){
            ++digits[i];
            if(digits[i] == 10) {
                digits[i] = 0;
                continue;
            }
            return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};