class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int> prefix_l(n + 1, 0);
        vector<int> prefix_r(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            char ch = s[i - 1];
            prefix_l[i] = prefix_l[i - 1];
            prefix_r[i] = prefix_r[i - 1];
            
            if (ch == 'R') prefix_l[i]++;
            else if (ch == 'L') prefix_l[i]--;
            else if (ch == 'U') prefix_r[i]++;
            else if (ch == 'D') prefix_r[i]--;
        }
        
        string x = s;
        set<pair<int, int>> cnt;
        for (int i = 0; i <= n - k; ++i) {
            int dx = prefix_l[i + k] - prefix_l[i];
            int dy = prefix_r[i + k] - prefix_r[i];
            cnt.insert({dx, dy});
        }
        return cnt.size();
    }
};©leetcode
