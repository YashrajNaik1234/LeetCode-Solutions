class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt(2),ans(2);
        for(int i(1);i < nums.size() - 1;i++){
            if(nums[i + 1] == nums[i] + nums[i - 1]) cnt++; else cnt = 2;
            ans = max(ans, cnt);
        }
        return ans;
    }
}
