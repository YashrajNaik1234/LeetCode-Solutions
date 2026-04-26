class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        if(n == 1) return nums;
        res.push_back(nums[0]);

        int left = nums[0];
        for(int i(1);i < n - 1;i++){
            int right = 0;
            for(int j = n - 1;j > i;j--){
                right = max(right, nums[j]);
            }

            if(nums[i] > left){
                res.push_back(nums[i]);
                left = nums[i];
            }
            else if(right < nums[i]){
                res.push_back(nums[i]);
            }
        }

        res.push_back(nums[n - 1]);
        return res;
    }
};
