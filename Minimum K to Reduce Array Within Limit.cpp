class Solution {
public:
    int nonpositive(int k, vector<int> nums){
        int res(0);
        for(int i(0);i < nums.size();i++){
            res += ((nums[i] + k - 1) / k);
        }

        return res;
    }
    int minimumK(vector<int>& nums) {
        int low = 1, high = 1e9;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nonpositive(mid, nums) <= pow(mid, 2)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};
