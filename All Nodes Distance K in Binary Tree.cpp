class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();

            if(cur -> left){
                mp[cur -> left] = cur;
                q.push(cur -> left);
            }

            if(cur -> right){
                mp[cur -> right] = cur;
                q.push(cur -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        markParent(root, mp);

        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q; q.push(target);
        int cur = 0; vis[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(cur++ == k) break;
            for(int i(0);i < size;i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr -> left and !vis[curr -> left]){
                    q.push(curr -> left); vis[curr -> left] = true;
                }
                if(curr -> right and !vis[curr -> right]){
                    q.push(curr -> right); vis[curr -> right] = true;
                }

                if(mp[curr] and !vis[mp[curr]]){
                    q.push(mp[curr]); vis[mp[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            ans.push_back(curr -> val);
        }

        return ans;
    }
};
