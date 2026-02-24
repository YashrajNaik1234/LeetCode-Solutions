class Solution {
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0); return ans;
    }
    void dfs(TreeNode *root,int cnt){
        cnt = 2 * cnt + root -> val;

        if(!root -> right and !root -> left){
            ans += cnt; return;
        }

        if(root -> left) dfs(root -> left, cnt);
        if(root -> right) dfs(root->right, cnt);
    }
};
