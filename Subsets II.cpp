class Solution {
public:
    void solve(int i, int n, vector<int>& v,vector<int>& x, vector<vector<int>>& ans){
        if(i >= n){
            ans.push_back(x); return;
        }

        x.push_back(v[i]);
        solve(i + 1, n, v, x, ans);
        x.pop_back();

        while(i + 1 < n and v[i] == v[i + 1]) i++;
        solve(i + 1, n, v, x, ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; vector<int> v;
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), nums, v, ans);
        return ans;
    }
};
