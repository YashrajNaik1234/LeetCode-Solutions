class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int r(arr.size() - 1);
        while(r > 0 and arr[r] >= arr[r - 1]) r--;

        int ans(r),l(0);
        while(l < r and (l == 0 or arr[l - 1] <= arr[l])){
            while(r < arr.size() and arr[l] > arr[r]) r++;
            
            ans = min(ans , r - l - 1); l++;
        }

        return ans;
    }
};
