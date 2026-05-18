class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int i(1);
        while(i < s.length()){
            if(abs((int)(s[i - 1] - '0') - (int)(s[i] - '0')) > 2) return false; i++;
        }

        return true;
    }
};
