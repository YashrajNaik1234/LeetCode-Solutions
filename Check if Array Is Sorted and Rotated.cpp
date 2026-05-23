class Solution {
public:
    bool check(vector<int>& nums) {
        int x(-1);
        for(int i(1);i < nums.size();i++){
            if(nums[i] < nums[i - 1]){
                x = i; break;
            }
        }
        if(x == -1) return 1;

        for(int i(x);i < nums.size() - 1;i++){
            if(nums[i] > nums[i + 1]) return 0;
        }

        if(nums[0] < nums[nums.size() - 1]) return 0;
        return 1;
    }
};
