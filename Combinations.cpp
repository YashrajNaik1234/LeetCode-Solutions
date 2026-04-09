class Solution {
public:
    void solve(int it, vector<int> x, vector<vector<int>> &ans, int n, int k){
        if(x.size() == k){
            ans.push_back(x); return;
        }

        for(int i(it);i <= n;i++){
            x.push_back(i);
            solve(i + 1, x, ans, n, k);
            x.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(1, res, ans, n, k);
        return ans;
    }
};
