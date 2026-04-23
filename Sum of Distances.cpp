class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> res;
        for (int i = 0; i < n; i++) res[nums[i]].push_back(i);

        vector<long long> ans(n);
        for (auto p : res) {
            auto x = p.second;
            long long total = accumulate(x.begin(), x.end(), 0LL), prefSum = 0;
            for (int i = 0; i < x.size(); i++) {
                ans[x[i]] = total - prefSum * 2 + x[i] * (2 * i - x.size());
                prefSum += x[i];
            }
        }
        
        return ans;
    }
};
