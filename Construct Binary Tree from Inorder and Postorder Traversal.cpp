class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postorderPos = 0;
    TreeNode* build(vector<int>& postorder, int left, int right){
        if (left > right) return nullptr;
        
        int rootVal = postorder[postorderPos++];
        TreeNode* root = new TreeNode(rootVal);
        
        int inorderPos = inorderIndex[rootVal];
        
        root -> right = build(postorder, inorderPos + 1, right);
        root -> left = build(postorder, left, inorderPos - 1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)  inorderIndex[inorder[i]] = i;
        reverse(postorder.begin(),postorder.end());
        return build(postorder, 0, inorder.size() - 1);
    }
};
