class Solution {
public:
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        
        int l = dfs(root -> left);
        int r = dfs(root -> right); 
        if(l == -1) return -1;
        if(r == -1) return -1;

        if(abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
