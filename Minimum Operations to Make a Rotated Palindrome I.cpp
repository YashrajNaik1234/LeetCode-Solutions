class Solution {
public:
    int minOperations(string s) {
        int n = s.size(),ans(INT_MAX);

        for(int i(0);i < n;i++){
            int cnt(i);
            for(int j(0);j < n / 2;j++){
                char a = s[(j + i) % n];
                char b = s[(n - 1 - j + i) % n];
                int x = (a - b + 26) % 26, y = (b - a + 26) % 26;
                cnt += min(x, y);
            }

            ans = min(ans, cnt);
        }

        return ans;
    }
};
