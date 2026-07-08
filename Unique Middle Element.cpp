class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int ans = 0;

        for (int i : nums) {
            if(i == nums[nums.size() / 2]) ans++;
        }
        return ans == 1;
    }
};
