const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(long long num) {
        if (num == 0) return "0";
        string ans = "";
        unsigned int n = num;

        int count(0), digit;
        while (n > 0) {
            digit = n % 16;
            ans = HEX[digit] + ans;
            n >>= 4;
        }
        
        return ans;
    }
};
