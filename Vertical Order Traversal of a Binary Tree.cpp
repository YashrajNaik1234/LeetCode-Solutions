class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto x = q.front(); q.pop();
            TreeNode* m = x.first;
            int a = x.second.first, b = x.second.second;
            
            mp[a][b].insert(m -> val);
            if(m -> left) q.push({m -> left,{a - 1, b + 1}});
            if(m -> right) q.push({m -> right,{a + 1, b + 1}}); 
        }
        
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int> x;
            for(auto j:i.second) x.insert(x.end(), j.second.begin(), j.second.end());
            ans.push_back(x);
        }

        return ans;
    }
};
