class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count(0);
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m ,0));;

        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0}); vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) count++;
            }
        }

        int ans = 0,cnt(0);
        vector<int> row = {-1, 0, 1 , 0};
        vector<int> col = {0 , -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second; q.pop();

            for(int i(0);i < 4;i++){ 
                int xRow = x + row[i], xCol = y + col[i]; ans = max(ans, z);

                if(xRow >= 0 and xRow < n and xCol >= 0 and xCol < m
                and vis[xRow][xCol] == 0 and grid[xRow][xCol] == 1){
                    q.push({{xRow, xCol}, z + 1}); vis[xRow][xCol] = 1; cnt++;
                }
            }
        }

        if(count != cnt) return -1;
        return ans;
    }
};
