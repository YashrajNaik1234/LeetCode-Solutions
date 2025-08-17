class Solution {
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root -> left);

        if(prev and root -> val < prev -> val){
            if(first == nullptr){
                first = prev; middle = root;
            }
            else last = root;
        }

        prev = root;
        inorder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first and last) swap(first -> val, last -> val);
        else if(first and middle) swap(first -> val, middle -> val);
    }
};
