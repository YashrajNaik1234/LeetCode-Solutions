class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> prefix(nums.size() + 1, 0);
        
        for(int i(0);i < nums.size();i++){
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        int ans(0);
        for(int i(0);i < nums.size();i++){
            for(int j(0);j <= i;j++){
                if(prefix[i + 1] > prefix[j]) ans++;
            }
        }

        return ans;
    }
};
