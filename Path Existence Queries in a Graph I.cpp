class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> cnt(n);

        for (int i = 1; i < n; i++) {
            cnt[i] = cnt[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> res;
        for (const auto &q : queries) {
            res.push_back(cnt[q[0]] == cnt[q[1]]);
        }

        return res;
    }
};
