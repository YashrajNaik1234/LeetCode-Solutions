class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q; bool flag(0); q.push(root);
        while(!q.empty()){
            int size = q.size(); vector<int> cnt(size);
            for(int i(0);i < size;i++){
                TreeNode* node = q.front(); q.pop();
                int index = (!flag) ? i : (size - i - 1);

                cnt[index] = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            flag = !flag; ans.push_back(cnt);
        }

        return ans;
    }
};
