class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool s02 = s1[0] == s2[2] and s1[2] == s2[0];
        bool b02 = s1[0] == s2[0] and s1[2] == s2[2];
        bool s13 = s1[1] == s2[3] and s1[3] == s2[1];
        bool b13 = s1[1] == s2[1] and s1[3] == s2[3];
        return ((s02 || b02) and (s13 || b13));
    }
};
