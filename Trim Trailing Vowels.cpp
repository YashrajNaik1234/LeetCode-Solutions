class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.length() - 1;
        while(i >= 0 and (s[i] == 'a' or s[i] == 'e' or s[i] =='i' or s[i] == 'o' or s[i] == 'u')) i--;
        return s.substr(0, i + 1);
    }
};
