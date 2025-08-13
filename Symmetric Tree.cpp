class Solution {
public:
    bool solve(TreeNode* n1,TreeNode* n2){
        if(n1 == NULL and n2 == NULL) return true;
        if(n1 == NULL or n2 == NULL) return false;

        return n1->val == n2->val and solve(n1->left, n2->right) and solve(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
