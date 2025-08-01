class Solution {
public:
    int maxIndex(vector<vector<int>>& mat, int n, int m, int col){
        int maxVal = -1, index = -1;
        for(int i(0);i < n;i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col]; index = i;
            }
        }

        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low(0), high(m - 1);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int x = maxIndex(mat, n, m, mid);

            int left = mid - 1 >= 0 ? mat[x][mid - 1] : -1;
            int right = mid + 1 < m ? mat[x][mid + 1] : -1;

            if(mat[x][mid] > left and mat[x][mid] > right) return {x, mid};
            else if(mat[x][mid] < left) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};
