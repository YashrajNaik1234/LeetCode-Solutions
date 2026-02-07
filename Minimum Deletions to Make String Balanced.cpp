class Solution {
public:
    int minimumDeletions(string s) {
        int cnt(0) , ans(0);
        for(auto ch:s) {
            if(ch == 'a') ans = min(ans + 1, cnt);
            else cnt++;
        }
        return ans;
    }
};
