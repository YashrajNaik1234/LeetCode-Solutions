class Solution {
public:
    int finalElement(vector<int>& nums) {
        if(nums.size() == 1) return nums.front();
        return max(nums.front(), nums.back());
    }
};
