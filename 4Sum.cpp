class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        if(nums.size() < 4) return ans;

        for (int i(0); i < nums.size() - 3; i++) {
            for(int j(i + 1);j < nums.size() - 2;j++){
                long long int x = target * 1ll - nums[i] * 1ll - nums[j] * 1ll;

                int left(j + 1),right(nums.size() - 1);
                while(left < right){
                    int sum = nums[left] + nums[right];

                    if(sum < x) left++;
                    else if(sum > x) right--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int s1 = nums[left],s2 = nums[right];
                        while(left < right and nums[left] == s1) left++;
                        while(left < right and nums[right] == s2) right--;
                    }
                }
                while(j + 1 < nums.size() - 1 and nums[j] == nums[j + 1]) j++;
            }
            while(i < nums.size() - 1 and nums[i] == nums[i + 1]) i++;
        }

        return ans;
    }
};
