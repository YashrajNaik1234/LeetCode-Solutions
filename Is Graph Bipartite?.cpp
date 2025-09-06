class Solution {
public:
    bool checkBFS(int x, vector<vector<int>>& graph, vector<int>& v){
        queue<int> q; q.push(x);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto i:graph[node]){
                if(v[i] == -1){
                    v[i] = !v[node]; q.push(i);
                }
                else if(v[i] == v[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool checkDFS(int x, vector<vector<int>>& graph, vector<int>& v){
        for(auto i: graph[x]){
            if(v[i] == -1){
                v[i] = !v[x];
                if(!checkDFS(i, graph, v)) return false;
            }
            else if(v[i] == v[x]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> v(graph.size(), -1);
        for(int i(0);i < graph.size();i++){
            if(v[i] == -1){
                v[i] = 0;
                if(!checkDFS(i, graph, v)) return false;
            }
        }

        return true;
    }
};
