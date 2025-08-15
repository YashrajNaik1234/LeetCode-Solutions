class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur -> left != nullptr){
                TreeNode* prev = cur -> left;
                while(prev -> right) prev = prev -> right;

                prev -> right = cur -> right;
                cur -> right = cur -> left;
                cur -> left = nullptr;
            }
            cur = cur -> right;
        }
    }
};
