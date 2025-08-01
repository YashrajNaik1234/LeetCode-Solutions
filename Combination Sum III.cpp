class Solution
{
public:
    void solve(int i, int j, int k, int sum, int n, vector<int> v, vector<int> x, vector<vector<int>>& ans)
    {   
        if (j >= k or sum >= n){
            if(sum == n and k == j) {
                ans.push_back(x);
            }
            return;
        }
        if (i >= v.size())
            return;

        x.push_back(v[i]);
        solve(i + 1, j + 1, k, sum + v[i], n, v, x, ans);
        x.pop_back();

        solve(i + 1, j, k, sum, n, v, x, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> x;
        solve(0, 0, k, 0, n, v, x, ans);
        return ans;
    }
};
