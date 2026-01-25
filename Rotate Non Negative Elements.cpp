class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> ans(nums), pos, x;
        for(int i(0);i < nums.size();i++){
            if(nums[i] >= 0){
                x.push_back(i); pos.push_back(nums[i]);
            }
        }

        if(x.size() == 0) return nums;
        rotate(pos.begin(), pos.begin() + (k % pos.size()), pos.end());
        for(int i(0);i < x.size();i++) ans[x[i]] = pos[i];

        return ans;
    }
};
