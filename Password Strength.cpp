class Solution {
public:
    int passwordStrength(string s) {
        int ans(0);
        unordered_set<char> st(s.begin(), s.end());

        for(auto i: st){
            if(islower(i)) ans++;
            else if(isupper(i)) ans += 2;
            else if(isdigit(i)) ans += 3;
            else ans += 5;
        }

        return ans;
    }
};
