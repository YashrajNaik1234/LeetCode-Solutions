class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int n, vector<int>& v, int sum, int tar, vector<int>& res) {
        if (i == n) {
            if (sum == tar) ans.push_back(res);
            return;
        }

        if (sum + v[i] <= tar) {
            res.push_back(v[i]);
            solve(i + 1, n, v, sum + v[i], tar, res);
            res.pop_back();
        }

        int x(i);
        while (i < n and v[x] == v[i]) i++;
        solve(i, n, v, sum, tar, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates.size(), candidates, 0, target, res);
        return ans;
    }
};
