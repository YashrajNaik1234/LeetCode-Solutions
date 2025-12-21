class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool> mp(1e5, 0);
        int ans = 0;

        for(int i(nums.size() - 1); i >= 0;i--){
            if(mp[nums[i]]){
                ans = i + 1; break;
            }
            mp[nums[i]] = 1;
        }

        return (ans + 2) / 3;
    }
};
