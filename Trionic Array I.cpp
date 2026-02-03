class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt(0);
        for(int i(0);i < nums.size() - 1;i++){
            if(nums[i + 1] > nums[i]) cnt |= 1;
            else if(nums[i + 1] < nums[i] and (cnt == 1 or cnt == 2)) cnt = 2;
            else return false;
        }

        return cnt == 3;
    }
};
