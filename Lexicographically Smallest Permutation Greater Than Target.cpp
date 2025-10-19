class Solution {
public:
    vector<int> cnt;
    string ans,res; int n;
    bool dfs(int i, bool x){
        if(i == n) return x;

        for(int j(0);j < 26;j++){
            if(cnt[j] == 0) continue;
            char ch = j + 'a';
            if(!x and ch < res[i]) continue;
            
            cnt[j]--; ans.push_back(ch);
            if(dfs(i + 1, (x or ch > res[i]))) return true;
            ans.pop_back(); cnt[j]++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        res = target; n = s.size(); cnt.assign(26, 0);
        for(auto i:s) cnt[i - 'a']++;  ans = "";
        if(dfs(0, false)) return ans;
        return "";
    }
};©leetcode
