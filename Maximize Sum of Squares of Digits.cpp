class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 or sum > num * 9LL) return "";

        string s; s.reserve(num);
        for(int i(0);i < num;i++){
            int x = min(9, sum);
            if(x < sum - 9 * (num - i - 1)) x =  sum - 9 * (num - i - 1);
            if(x < (i == 0 ? 1 : 0)) x = i == 0 ? 1 : 0;
            s.push_back(char('0' + x)); sum -= x;
        }

        return s;
    }
};
