class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        if(s.front() - '0' == x) return false;

        while(n > 0){
            if(n % 10 == x) return true; n /= 10;
        }

        return false;
    }
};
