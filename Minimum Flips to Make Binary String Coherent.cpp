class Solution {
public:
    int minFlips(string s) {
        int one(0),zero(0);
        for(auto i:s) if(i == '1') one++; else zero++;

        int ans = min(one, zero);
        if(one > 0) ans = min(ans, one - 1);

        if(s.length() >= 2){
            if(s.front() == '1' and s[s.length() - 1] == '1') ans = min(ans, one - 2);
            else if(s.front() == '1' or s[s.length() - 1] == '1') ans = min(ans, one);
            else ans = min(ans, one + 2);
        }

        return ans;
    }
};
