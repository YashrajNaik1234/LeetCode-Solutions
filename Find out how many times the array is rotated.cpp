class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int ans(INT_MAX);
        int low(0),high(nums.size() - 1);
        int index(-1);

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] >= nums[low]){
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }

        return index;
    }
};
