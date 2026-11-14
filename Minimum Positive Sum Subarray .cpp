class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans(INT_MAX); bool k(false);

        for(int i(l);i <= r;i++){
            int sum(0);

            for(int j(0);j < i;j++) sum += nums[j];

            if(sum > 0){
                ans= min(ans , sum); k = true;
            }

            for(int j(i);j < nums.size();j++){
                sum += nums[j] - nums[j - i];
                if(sum > 0){
                    ans = min(ans , sum); k = true;
                }
            }
        }

        return k ? ans : -1;
    }
};
