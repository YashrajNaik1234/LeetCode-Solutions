class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int left(-1);
        for(int i(1);i < nums.size();i++){
            if(nums[i - 1] >= nums[i]) left = i - 1;
        }

        if(left == -1) return 0;
        return left + 1;
    }
};
