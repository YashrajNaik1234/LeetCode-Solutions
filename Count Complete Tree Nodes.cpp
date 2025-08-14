class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + solve(root->left) + solve(root->right);
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};
