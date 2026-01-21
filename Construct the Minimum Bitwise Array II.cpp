class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);

        for(int i(0);i < nums.size();i++){
            int mx(INT_MAX); bool k(0);

            for(int j(0);j <= 30;j++){
                if((nums[i] >> j) & 1){
                    int cnt(nums[i] & ~(1 << j));

                    if(cnt < 0) continue;
                    if((cnt | cnt + 1) == nums[i]){
                        if(cnt < mx) mx = cnt , k = 1;
                    }
                }
            }

            if(k) ans[i] = mx;
        }
        return ans;
    }
};
