class Solution {
public:
    const int mod = 1e9 + 7;
    long long Pow(long long x, long long n, long long ans){
        if(n == 0) return ans;
        if(n & 1) return Pow(x, n - 1, (x * ans) % mod);
        return Pow((x * x) % mod, n / 2, ans);
    }
    int countGoodNumbers(long long n) {
        return (int)((Pow(5, (n + 1) / 2, 1LL) * Pow(4, n / 2, 1LL)) % mod);
    }
};
