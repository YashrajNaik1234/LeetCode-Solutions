class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                count++;
                if (rand() % count == 0) ans = i;
            }
        }
        return ans;
    }
};
