class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& v){
        if(i < 0 or j < 0) return 0;
        if(i >= v.size()) i = v.size() - 1;
        if(j >= v[0].size()) j = v[0].size() - 1;
        return v[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> sum(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i(0);i < mat.size();i++){
            for(int j(0);j < mat[0].size();j++){
                sum[i][j] = mat[i][j] + solve(i - 1, j, sum) + solve(i, j - 1, sum) - solve(i - 1, j - 1, sum);
            }
        }

        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i(0);i < mat.size();i++){
            for(int j(0);j < mat[0].size();j++){
                ans[i][j] = solve(i + k, j + k, sum) - solve(i + k, j - k - 1, sum) - solve(i - k - 1, j + k, sum) + solve(i - k - 1, j - k - 1, sum);
            }
        }

        return ans;
    }
};
