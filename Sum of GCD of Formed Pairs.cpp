class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefGCD(nums.size(), 0);
        long long mx = 0;

        for(int i = 0;i < nums.size();i++){
            mx = max(mx, (long long)nums[i]);
            prefGCD[i] = __gcd(mx, (long long)nums[i]);
        }

        sort(prefGCD.begin(), prefGCD.end());
        long long ans = 0; int l = 0, r = nums.size() - 1;
        while(l < r){
            ans += __gcd(prefGCD[l], prefGCD[r]); l++; r--;
        }

        return ans;
    }
};
