class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k){
        if(root == nullptr) return;

        solve(root -> left, cnt, ans, k); cnt++;
        if(cnt == k){
            ans = root -> val; return;
        }
        solve(root -> right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt(0); int ans(0);
        solve(root, cnt, ans, k);
        return ans;
    }
};
