class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int i(0);i < nums.size();i++){
            int k = nums[i];
            for(int j = 1;j * j <= nums[i];j++){
                if(nums[i] % j == 0){
                    if(s.count(j)) k = min(k, j);
                    if(s.count(nums[i] / j)) k = min(k, nums[i] / j);
                }
            }

            ans += k;
        }

        return ans;
    }
};
