class Solution {
public:
    string reversePrefix(string s, int k) {
        string x;

        for(int i(k - 1);i >= 0;i--) x += s[i];
        for(int i(k);i < s.length();i++) x += s[i];

        return x;
    }
};
