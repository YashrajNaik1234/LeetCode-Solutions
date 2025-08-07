class Solution {
public:
    int solve(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left(0),right(0); int sum(0),ans(0);

        while(right < nums.size()){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left]; left++;
            }

            ans += (right - left + 1); right++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
