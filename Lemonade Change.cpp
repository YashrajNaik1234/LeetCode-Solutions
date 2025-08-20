class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a(0), b(0), c(0);

        for (int i(0); i < bills.size(); i++) {
            if (bills[i] == 5) a++;
            else if (bills[i] == 10) {
                if (a > 0) {
                    a--; b++;
                } 
                else return 0;
            } else if (bills[i] == 20) {
                if (a > 0 && b > 0) {
                    a--; b--;
                } 
                else if (a >= 3) a -= 3;
                else return 0;
            }
        }

        return 1;
    }
};
