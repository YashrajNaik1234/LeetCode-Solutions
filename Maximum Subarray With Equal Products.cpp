class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2, mul = 1, n = nums.size();
        int start = 0, end = 0;

        while (end < n) {
            while (gcd(mul, nums[end]) > 1) {
                mul /= nums[start]; start++;
            }
            mul *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        
        return res;
    }
};
