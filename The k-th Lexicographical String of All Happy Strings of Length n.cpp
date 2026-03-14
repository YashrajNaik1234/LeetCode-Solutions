class Solution {
public:
    string getHappyString(int n, int k) {
        string x = "";
        vector<string> v;
        solve(n, x, v);

        if (v.size() < k) return "";
        return v[k - 1];
    }
    void solve(int n, string x, vector<string> &v) {
        if (x.size() == n) {
            v.push_back(x); return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (x.size() > 0 && x.back() == c) continue;
            solve(n, x + c, v);
        }
    }
};
