class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i(1);
        for(i;i <= nums.size();i++){
            if(find(nums.begin(),nums.end(),k * i) == nums.end()) return k * i;
        }
        return k * i;
    }
};
