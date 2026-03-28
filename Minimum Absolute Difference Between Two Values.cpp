class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int i(-1),j(-1);

        for(int k(0);k < nums.size();k++) if(nums[k] == 1){
            i = k; break;
        }
        for(int k(0);k < nums.size();k++) if(nums[k] == 2){
            j = k; break;
        }

        if(j == -1 or i == -1) return -1;
        int ans(abs(i - j));
        for(int k = min(i, j) + 1;k < nums.size();k++){
            if(nums[k] == 1) ans = min(ans, abs(k - j)), i = k;
            else if(nums[k] == 2) ans = min(ans, abs(k - i)), j = k;
        }

        return ans;
    }
};
