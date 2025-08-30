class Solution {
public:
    int getLeastFrequentDigit(int n) {
        n = abs(n);

        vector<int> freq(10, 0);
        if (n == 0) freq[0] = 1;
        while (n > 0) {
            int d = n % 10; freq[d]++;  n /= 10;
        }

        int minFreq = INT_MAX, ans = -1;
        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0) {
                if (freq[d] < minFreq || (freq[d] == minFreq && d < ans)) {
                    minFreq = freq[d]; ans = d;
                }
            }
        }

        return ans;
    }
};
