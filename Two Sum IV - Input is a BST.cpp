class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse; pushAll(root);
    }
    
    int next() {
        TreeNode* x = st.top(); st.pop();
        if(!reverse) pushAll(x -> right);
        else pushAll(x -> left);
        return x -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node){
        for(;node != nullptr;){
            st.push(node);
            if(reverse) node = node -> right;
            else node = node -> left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator left(root, false);
        BSTIterator right(root , true);

        int l = left.next();
        int r = right.next();
        while(l < r){
            if(l + r == k) return true;
            else if(l + r < k) l = left.next();
            else r = right.next();
        }

        return false;
    }
};
