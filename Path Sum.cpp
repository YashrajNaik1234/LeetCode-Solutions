class Solution {
public:
    bool res = false;
    void solve(TreeNode* root,int target, int sum){
        if(sum + root -> val == target and !root -> left and !root -> right) res = true;
        if(root -> left) solve(root -> left, target, sum + root -> val);
        if(root -> right) solve(root -> right, target, sum + root -> val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;  if(!root) return false;
        solve(root, targetSum, sum);
        return res;
    }
};
