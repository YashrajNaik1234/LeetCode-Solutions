class Solution {
public:
    double myPow(double x, int n) {
        long long y = n;
        if(y < 0) x = 1 / x, y = -y;
        return Pow(x, y);
    }
    double Pow(double x, int n){
        if(n == 0) return 1.0;
        double half = Pow(x, n / 2);

        if(n & 1) return half * half * x;
        return half * half;
    }
};
