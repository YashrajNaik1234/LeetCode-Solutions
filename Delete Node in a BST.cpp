class Solution {
public:
    TreeNode* findLast(TreeNode* root){
        if(root -> right == nullptr) return root;
        return findLast(root -> right);
    }
    TreeNode* solve(TreeNode* root){
        if(root -> left == nullptr) return root -> right;
        else if(root -> right == nullptr) return root -> left;

        TreeNode* temp = root -> right;
        TreeNode* x = findLast(root -> left);
        x -> right = temp; return root -> left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root -> val == key) return solve(root);

        TreeNode* dummy = root;
        while(root != nullptr){
            if(root -> val > key){
                if(root -> left and root -> left -> val == key){
                    root -> left = solve(root -> left); break;
                }
                else root = root -> left;
            }
            else{
                if(root -> right and root -> right -> val == key){
                    root -> right = solve(root -> right); break;
                }
                else root = root -> right;
            }
        }

        return dummy;
    }
};
