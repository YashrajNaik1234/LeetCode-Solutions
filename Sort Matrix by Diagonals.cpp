class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(),0));

        int j(grid.size()); 
        while(j > 0){
            int x,i(0);
            priority_queue<int,vector<int>,greater<int>> q;
            for(x = j;x < grid.size();x++){
                q.push(grid[i++][x]);
            }
            
            x = j; i = 0;
            while(!q.empty()){
                ans[i++][x++] = q.top(); q.pop();
            }

            j--;
        }

        j = 0;
        while(j < grid.size()){
            int x,i(0);
            priority_queue<int,vector<int>> q;
            for(x = j;x < grid.size();x++){
                q.push(grid[x][i++]);
            }
            
            x = j; i = 0;
            while(!q.empty()){
                ans[x++][i++] = q.top(); q.pop();
            }

            j++;
        }

        return ans;
    }
};
