class Solution {
public:
    bool scoreBalance(string s) {
        int x = 0;
        for(auto i:s) x += i - 96;

        int cnt(0);
        for(auto i:s){
            cnt += i - 96;
            if(cnt == x - cnt) return true;
        }
        return false;
    }
};
