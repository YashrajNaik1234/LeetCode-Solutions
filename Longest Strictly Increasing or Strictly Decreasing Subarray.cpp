class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans(1),cnt(1);

        for(int i(1);i < nums.size();i++){
            if(nums[i] > nums[i - 1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        for(int i(nums.size() - 1);i >= 1;i--){
            if(nums[i] < nums[i - 1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
        }

        return ans;
    }
};
