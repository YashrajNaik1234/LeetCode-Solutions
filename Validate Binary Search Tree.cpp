class Solution {
public:
    bool solve(TreeNode* root, long mini, long maxi){
        if(root == nullptr) return true;
        if(root -> val <= mini or root -> val >= maxi) return false;
        return solve(root -> left, mini, root -> val) and solve(root -> right, root -> val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
