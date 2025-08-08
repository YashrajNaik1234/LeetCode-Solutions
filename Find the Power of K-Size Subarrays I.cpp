class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;

        int n = nums.size();
        vector<int> arr;
        int left(0),right(1);

        while(right < nums.size()){
            bool x = nums[right] - nums[right - 1] != 1;
            
            if(x){
                while(left < right and left + k - 1 < n){
                    arr.push_back(-1); left++;
                }
                left = right;
            }
            else if(right - left == k - 1){
                arr.push_back(nums[right]); left++;
            }

            right++;
        }

        return arr;
    }
};
