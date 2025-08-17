class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for(auto& x: nums) x = abs(x);
        sort(nums.begin(),nums.end());

        long long ans(0);
        for(int i(0);i < nums.size();i++){
            auto it = upper_bound(nums.begin(),nums.end(), 2 * nums[i]);
            ans += it - nums.begin() - i - 1;
        }

        return ans;
    }
};©leetcode
