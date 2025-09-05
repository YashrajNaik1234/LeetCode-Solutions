class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long d = num1 - 1ll * num2 * k;
            if (d < k) return -1;
            if (k >= __builtin_popcountll(d)) return k;
        }
        return -1;
    }
};
