class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>> mat){
        vis[i][j] = 1;
        int n = mat.size();
        int m = mat[0].size();

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};
        for(int x(0);x < 4;x++){
            int Row = i + row[x];
            int Col = j + col[x];

            if(Row >= 0 and Col >= 0 and Row < n and Col < m
            and !vis[Row][Col] and mat[Row][Col] == 'O'){
                dfs(Row, Col, vis, mat);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i(0);i < m;i++){
            if(!vis[0][i] and board[0][i] == 'O'){
                dfs(0, i, vis, board);
            }

            if(!vis[n - 1][i] and board[n - 1][i] == 'O'){
                dfs(n - 1, i, vis, board);
            }
        }

        for(int i(0);i < n;i++){
            if(!vis[i][0] and board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }

            if(!vis[i][m - 1] and board[i][m - 1] == 'O'){
                dfs(i, m - 1, vis, board);
            }
        }

        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(!vis[i][j] and board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
