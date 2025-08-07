class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left(0),right(0); int sum(0),cnt(0);

        while(right < nums.size()){
            sum += (nums[right] % 2);

            while(sum > k){
                sum -= nums[left] % 2; left++;
            }

            cnt += right - left + 1; right++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
