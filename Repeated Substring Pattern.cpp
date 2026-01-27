class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i == 0) {
                string repeated = "";
                for (int j = 0; j < s.length() / i; j++) repeated += s.substr(0, i);
                if (repeated == s) return true;
            }
        }
        return false;
    }
};
