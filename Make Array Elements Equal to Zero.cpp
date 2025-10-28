class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0, sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, rightSum = sum;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) ans++;
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) ans++;
            } 
            else {
                leftSum += nums[i]; rightSum -= nums[i];
            }
        }
        
        return ans;
    }
};
