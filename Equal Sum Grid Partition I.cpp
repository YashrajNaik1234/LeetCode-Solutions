class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum(0);
        for(auto& row : grid) sum += accumulate(row.begin(), row.end(), 0LL);
        if (sum & 1) return 0;

        const long long target(sum / 2);
        const int r(grid.size()), c(grid[0].size());
        long long rowSum(0), colSum(0);

        for(int i(0); rowSum < target && i < r; i++) rowSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        for(int j(0); colSum < target && j < c; j++) for(int i(0); i < r; i++) colSum += grid[i][j];

        return rowSum == target or colSum==target;
    }
};
