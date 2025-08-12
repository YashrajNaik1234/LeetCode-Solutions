class Solution {
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root); return diameter;
    }
    int solve(TreeNode* root){
        if(root == nullptr) return 0;

        int l = solve(root -> left);
        int r = solve(root -> right);

        diameter = max(diameter, l + r);
        return  1 + max(l, r);
    }
};
