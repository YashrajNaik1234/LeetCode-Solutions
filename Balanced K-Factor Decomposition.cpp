class Solution {
public:
    vector<int> ans;
    int cnt = INT_MAX;

    void dfs(int n, int idx, vector<int>& v, int k) {
        if (k == 1) {
            v.push_back(n);
            int mx = *max_element(v.begin(), v.end());
            int mn = *min_element(v.begin(), v.end());
            int diff = mx - mn;
            if (diff < cnt) {
                cnt = diff; ans = v;
            }
            v.erase(v.begin() + v.size() - 1);
            return;
        }

        for (int i = idx; i * i <= n; i++) {
            if(n % i == 0){
                v.push_back(i);
                dfs(n / i, i, v, k - 1);
                v.erase(v.begin() + v.size() - 1);
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> res;
        dfs(n, 1, res, k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
