class Solution {
public:
    TreeNode* build(vector<int>& v, int& i, int j){
        if(i == v.size() or v[i] > j) return nullptr;

        TreeNode* root = new TreeNode(v[i++]);
        root -> left = build(v, i, root -> val);
        root -> right = build(v, i, j);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; return build(preorder, i, INT_MAX);
    }
};
