class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& adj, int s){
        vector<int> x(n, -1);
        queue<int> q;

        x[s] = 0; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto i:adj[u]){
                if(x[i] == -1){
                    x[i] = x[u] + 1; q.push(i);
                }
            }
        }

        return x;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> a = bfs(n, adj, x);
        vector<int> b = bfs(n, adj, y);
        vector<int> c = bfs(n, adj, z);

        int cnt(0);
        for(int i(0);i < n;i++){
            vector<long long> q;
            q.push_back(a[i]);
            q.push_back(b[i]);
            q.push_back(c[i]);
            sort(q.begin(), q.end());

            if(q[0] * q[0] + q[1] * q[1] == q[2] * q[2]) cnt++;
        }

        return cnt;
    }
};
