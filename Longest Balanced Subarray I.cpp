class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i(0);i < nums.size();i++){
            unordered_set<int> even, odd;
            for(int j(i);j < nums.size();j++){
                if(nums[j] & 1) odd.insert(nums[j]);
                else even.insert(nums[j]);

                if(odd.size() == even.size()) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
