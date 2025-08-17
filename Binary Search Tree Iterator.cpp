class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* x = st.top(); st.pop();
        pushAll(x -> right);
        return x -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* root){
        for(;root != nullptr; st.push(root), root = root -> left);
    }
};
