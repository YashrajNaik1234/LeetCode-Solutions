class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> freq; 
        int start = 0, cnt = 0;
        
        for (int end = 0; end < n; end++) {
            freq[nums[end]]++;
            if (freq[nums[end]] == k + 1) cnt++;
            if (cnt > 0) {
                freq[nums[start]]--;
                if (freq[nums[start]] == k) cnt--;
                start++;
            }
        }

        return n - start;
    }
};
