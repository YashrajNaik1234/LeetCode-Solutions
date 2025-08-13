class Solution {
public:
    bool isLeaf(TreeNode* root) {
        if (!root->left and !root->right)
            return true;
        return false;
    }
    void solvePath(TreeNode* root, vector<string>& ans,string x) {
        x += to_string(root -> val);

        if (isLeaf(root)) {
            ans.push_back(x); return;
        }

        if (root -> left) solvePath(root->left, ans, x + "->");
        if (root -> right) solvePath(root->right, ans, x + "->");

        x.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans; string x;
        if (!root) return ans;
        
        solvePath(root, ans, x);
        return ans;
    }
};
