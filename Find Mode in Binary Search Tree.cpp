class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> cnt;
        dfs(root, cnt); int maxFreq = 0;
        
        for(auto [key, val]: cnt) maxFreq = max(maxFreq, val);
        
        vector<int> ans;
        for(auto [key, val]:cnt) if(val ==  maxFreq) ans.push_back(key);
        return ans;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& mp){
        if(root == nullptr) return;

        mp[root -> val]++;
        dfs(root -> left, mp);
        dfs(root -> right, mp);
    }
};
