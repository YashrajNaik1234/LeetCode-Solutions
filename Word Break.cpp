class Solution {
public:
    unordered_map<int, bool> memo;
    bool solve(int i, string s, vector<string> dict, string x) {
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        for (auto j : dict) {
            if (j == s.substr(i, j.size()))
                if (solve(i + j.size(), s, dict, x + j))
                    return 1;
        }

        memo[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return solve(0, s, wordDict, "");
    }
};
