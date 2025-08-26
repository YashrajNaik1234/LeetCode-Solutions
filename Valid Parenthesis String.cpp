class Solution {
public:
    bool checkValidString(string s) {
        int mx(0), min(0);
        for (auto i : s) {
            if (i == ')') {
                mx--;
                min--;
            } else if (i == '(') {
                mx++;
                min++;
            } else {
                mx++;
                min--;
            }

            if (mx < 0)
                return false;
            min = max(0, min);
        }
        
        return min == 0;
    }
};
