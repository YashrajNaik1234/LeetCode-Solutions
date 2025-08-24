class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt(0), left(0),ans(0);

        for(int i(0);i < nums.size();i++){
            cnt += (nums[i] == 0);

            while(cnt > 1){
                cnt -= (nums[left] == 0); left++;
            }

            ans = max(ans, i - left);
        }

        return ans;
    }
};
