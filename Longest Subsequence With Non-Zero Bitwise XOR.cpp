class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x(0); bool k(0);
        if(nums.size() == 0) return 0;
        for(auto i:nums){
            x ^= i; if(x != 0) k = 1;
        }

        if(x != 0) return nums.size();
        else if(k) return nums.size() - 1;
        return 0;
    }
};©leetcode
