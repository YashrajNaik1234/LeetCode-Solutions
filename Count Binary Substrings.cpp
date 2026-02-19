class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0, curr = 1, total = 0;
        
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) curr++;
            else {
                total += min(prev, curr); prev = curr; curr = 1;
            }
        }
        
        total += min(prev, curr);
        return total;
    }
};
