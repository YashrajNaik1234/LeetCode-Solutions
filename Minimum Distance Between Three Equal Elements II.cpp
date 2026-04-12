class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) next[i] = occur[nums[i]];
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (next[i] != -1) {
                if (next[next[i]] != -1) ans = min(ans, next[next[i]] - i);
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
