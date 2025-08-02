class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int s(0),ans(0);

        for(int e(0);e < nums.size();e++){
            while(1.0 * nums[e] / k > nums[s]) s++;
            ans = max(ans, e - s + 1);
        }

        return nums.size() - ans;
    }
};
