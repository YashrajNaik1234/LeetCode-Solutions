class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) return costs[0] + 1;
        
        vector<int> dp(n + 1); 
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = min(costs[1] + 4, dp[1] + costs[1] + 1);

        for(int i(3);i <= n;i++){
            dp[i] = costs[i - 1] + min({dp[i - 1] + 1, dp[i - 2] + 4, dp[i - 3] + 9});
        }
        
        return dp[n];
    }
};©leetcode
