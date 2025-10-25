class Solution {
public:
    string lexSmallest(string s) {
        string ans(1, '{');
        for(int i(1);i <= s.length();i++){
            string a = s; reverse(a.begin(),a.begin() + i); if(a < ans) ans = a;
            string b = s; reverse(b.end() - i, b.end()); if(b < ans) ans = b;
        }
        return ans;
    }
};
