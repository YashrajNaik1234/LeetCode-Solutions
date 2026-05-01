class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int mSum = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) mSum += i * nums[i];

        int res = mSum;
        for (int i = n - 1; i > 0; i--) {
            mSum += numSum - n * nums[i]; res = max(res, mSum);
        }

        return res;
    }
};
