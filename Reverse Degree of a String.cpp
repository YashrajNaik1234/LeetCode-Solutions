class Solution {
public:
    int reverseDegree(string s) {
        int ans(0), cnt(1);
        for(auto i: s){
            ans += abs(26 - (int)(i - 'a')) * cnt; cnt++;
        }

        return ans;
    }
};
