class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1ll * k * (*max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end()));
    }
};©leetcode
