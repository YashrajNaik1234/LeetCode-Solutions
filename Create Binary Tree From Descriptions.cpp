class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        unordered_set<int> child, parent;
        unordered_map<int, vector<pair<int,int>>> v;

        for(auto i: nums){
            parent.insert(i[0]);
            parent.insert(i[1]);
            child.insert(i[1]);
            v[i[0]].emplace_back(i[1], i[2]);
        }

        for(auto it = parent.begin(); it != parent.end();){
            if(child.find(*it) != child.end()) it = parent.erase(it);
            else it++;
        }

        TreeNode* root = new TreeNode(*parent.begin());
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* p = q.front(); q.pop();

            for(auto it: v[p -> val]){
                TreeNode* c = new TreeNode(it.first);
                q.push(c);

                if(it.second == 1) p -> left = c;
                else p -> right = c;
            }
        }

        return root;
    }
};
