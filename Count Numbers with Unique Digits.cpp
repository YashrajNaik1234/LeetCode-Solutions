class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        else if(n == 1) return 10;

        int ans = 10;
        for(int i(2);i <= n;i++){
            int temp = 9, res = 9, count(i - 1);
            while(count--){
                temp *= res--;
            }

            ans += temp;
        }

        return ans;
    }
};
