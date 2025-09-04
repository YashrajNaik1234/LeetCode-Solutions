class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if((i == 0 or j == 0 or i == n - 1 or j == m - 1) and grid[i][j] == 1){
                    q.push({i, j}); vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0 ,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second; q.pop();

            for(int i(0);i < 4;i++){
                int r = x + delrow[i];
                int c = y + delcol[i];

                if(r >= 0 and c >= 0 and r < n and c < m
                and !vis[r][c] and grid[r][c] == 1){
                    q.push({r, c}); vis[r][c] = 1;
                }
            }
        }

        int ans(0);
        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(!vis[i][j] and grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }
};
