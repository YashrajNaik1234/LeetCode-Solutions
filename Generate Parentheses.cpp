class Solution {
public:
    void solve(int n, int i, int j, string s, vector<string>& ans){
        if(i == n and j == n){
            ans.push_back(s); return;
        }

        if(i < n) solve(n, i + 1, j, s + "(", ans);
        if(j < i) solve(n, i, j + 1, s + ")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = ""; solve(n, 0, 0, s, ans);
        return ans;
    }
};
