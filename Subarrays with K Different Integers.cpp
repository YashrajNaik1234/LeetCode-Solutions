class Solution {
public:
    int solve(vector<int>& nums, int k){
        int left(0),right(0),cnt(0);
        unordered_map<int,int> mp;

        while(right < nums.size()){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            cnt += right - left + 1;
            right++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
