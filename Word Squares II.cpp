class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> s(words);
        sort(s.begin(),s.end());

        vector<vector<int>> adj(26);
        for(int i(0);i < s.size();i++){
            adj[s[i][0] - 'a'].push_back(i);
        }
        vector<vector<string>> ans;

        for(int i(0);i < s.size();i++){
            int x = s[i][0] - 'a';
            if(adj[x].empty()) continue;
            for(auto j: adj[x]){
                if(i == j) continue;
                int y = s[i][3] - 'a';
                if(adj[y].empty()) continue;
                for(auto k: adj[y]){
                    if(k == i or k == j) continue;
                    int z = s[j][3] - 'a';
                    if(adj[z].empty()) continue;
                    for(auto l: adj[z]){
                        if(l == i or l == j or l == k) continue;
                        if(s[l][3] == s[k][3]){
                            ans.push_back({s[i], s[j], s[k], s[l]});
                        }
                    }
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
