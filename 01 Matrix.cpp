class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second; q.pop();

            for(int i(0);i < 4;i++){
                int Row = x + row[i], Col = y + col[i];
                if(Row >= 0 and Row < n and Col >= 0 and Col < m
                and mat[Row][Col] > mat[x][y] + 1){
                    mat[Row][Col] = mat[x][y] + 1; q.push({Row, Col});
                }
            }
        }

        return mat;
    }
};
