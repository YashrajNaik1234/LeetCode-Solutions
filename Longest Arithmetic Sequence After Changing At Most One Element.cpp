class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<int> l(n, 2), r(n, 2);
        for(int i(2);i < n;i++){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) l[i] = l[i - 1] + 1;
        }
        for(int i(n - 3);i >= 0;i--){
            if(nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) r[i] = r[i + 1] + 1;
        }

        int ans = 2;
        for(int i(0);i < n;i++){
            ans = max({ans, l[i], r[i]});
        }

        for(int i(1);i < n - 1;i++){
            long long left = nums[i - 1];
            long long right = nums[i + 1];

            if((right - left) % 2 == 0){
                long long diff = (right - left) / 2;

                int leftLen = 1,rightLen = 1;
                if(i >= 2 && nums[i - 1] - nums[i - 2] == diff) leftLen = l[i - 1];
                if(i + 2 < n && nums[i + 2] - nums[i + 1] == diff) rightLen = r[i + 1];

                ans = max(ans, leftLen + 1 + rightLen);
            }
            ans = max(ans, l[i - 1] + 1);
            ans = max(ans, r[i + 1] + 1);
        }

        ans = max(ans, r[1] + 1);
        ans = max(ans, l[n - 2] + 1);

        return min(ans, n);
    }
};
