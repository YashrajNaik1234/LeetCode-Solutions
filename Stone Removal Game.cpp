class Solution {
public:
    bool canAliceWin(int n) {
        int k(10); bool ans(false);
        while(k > 0 or n > 0){
            if(n - k < 0) break; n -= k; k--; ans = !ans;
        }

        return ans;
    }
};
