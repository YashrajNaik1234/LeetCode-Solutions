class Solution {
public:
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0 , -1, 0, 1};
    void dfs(int i, int j, int init, vector<vector<int>>& ans, int color){
        ans[i][j] = color;
        int n = ans.size(), m = ans[0].size();
        for(int x(0);x < 4;x++){
            int xRow = i + row[x], xCol = j + col[x];
            if(xRow >= 0 and xRow < n and xCol >= 0 and xCol < m
                and ans[xRow][xCol] == init and ans[xRow][xCol] != color){
                    dfs(xRow, xCol, ans[xRow][xCol], ans, color);;
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, init, ans, color);
        return ans;
    }
};
