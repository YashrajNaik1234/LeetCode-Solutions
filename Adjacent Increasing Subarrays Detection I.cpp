class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(nums.size() / k < 2) return false; if(k == 1) return true;

        vector<int> cnt(nums.size() , 0);
        int l(0), r(1);
        
        while(r < nums.size()){
            while(r < nums.size() and nums[r] > nums[r - 1]){
                if(r - l + 1 == k) cnt[l] = 1 , l++; r++;
            }
            l = r; r++;
        }

        for(int i(0);i < nums.size() - k;i++)
            if(cnt[i] and cnt[i + k]) return true;

        return false;
    }
};
