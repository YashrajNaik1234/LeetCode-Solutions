class Solution {
    static const int M = 1e5 + 1;
    int freq[M];
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int xMax = 0;

        for (int x : costs) {
            freq[x]++; xMax = max(xMax, x);
        }

        int cnt = 0;
        for (int i = 1; i <= xMax; i++) {
            if (freq[i] == 0) continue;
            int buy = min(coins / i, freq[i]);

            if (buy == 0) break;
            cnt += buy; coins -= buy * i;
        }

        return cnt;
    }
};
