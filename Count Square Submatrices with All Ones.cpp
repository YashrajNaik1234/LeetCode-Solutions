class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans(0);
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i(0);i < matrix.size();i++){
            for(int j(0);j < matrix[0].size();j++){
                if(matrix[i][j]){
                    dp[i + 1][j + 1] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i][j]});
                }

                ans += dp[i + 1][j + 1];
            }
        }

        return ans;
    }
};
