class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<long long> dp(n, 0); dp[0] = nums[0];
        for(int i = 1;i < n; i++){
            if(colors[i] != colors[i - 1]) dp[i] = max(dp[i], nums[i] + dp[i - 1]);
            else{
                if(i > 1) dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
                else dp[i] = max(dp[i - 1], nums[i] * 1ll);
            }
        }

        return dp[nums.size() - 1];
    }
};
