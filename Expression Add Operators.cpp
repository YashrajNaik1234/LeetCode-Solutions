class Solution {
public:
    void solve(vector<string>& ans, string path, string num, int target,
               int pos, long long curr, long long prev) {
        if (pos == num.size()) {
            if (curr == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0')
                break;

            string part = num.substr(pos, i - pos + 1);
            long long n = stoll(part);

            if (pos == 0) solve(ans, path + part, num, target, i + 1, n, n);
            else {
                solve(ans, path + '+' + part, num, target, i + 1, curr + n, n);
                solve(ans, path + '-' + part, num, target, i + 1, curr - n, -n);
                solve(ans, path + '*' + part, num, target, i + 1, curr - prev + prev * n,
                      prev * n);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        string path;
        solve(ans, path, num, target, 0, 0, 0);
        return ans;
    }
};
