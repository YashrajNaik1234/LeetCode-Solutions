class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.find('0') == -1) return 1;
        return s.find('0') > s.find_last_of('1');
    }
};
