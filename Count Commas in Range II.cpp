class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, st = 1;
        int digits = 1;

        while(st <= n){
            long long up = min(n, st * 10 - 1);
            if(up >= st){
                ans += ((up - st + 1) * ((digits - 1) / 3));
            }
            st *= 10; digits++;
        }

        return ans;
    }
};
