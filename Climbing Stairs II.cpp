class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, INT_MAX); dp[0] = 0;

        for(int i(1);i <= n;i++){
            for(int j(1);j <= 3;j++){
                if(i - j >= 0 and dp[i - j] != INT_MAX) dp[i] = min(dp[i], dp[i - j] + costs[i - 1] + j * j);
            }
        }
        
        return dp[n];
    }
};©leetcode
