class Solution {
public:
    vector<vector<int>>dirs = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
    
    bool inboard(const vector<vector<char>>& board, int x, int y){
        return (x >= 0 and x < board.size() and y >= 0 and y < board[0].size() );
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        if(!inboard(board, x, y)) return;
        if(board[x][y] == 'B') return;
        int count = 0;
        for(auto d : dirs)
            if(inboard(board, x + d[0], y + d[1]) && board[x + d[0]][y + d[1]] == 'M')  count++;
        
        
        if(count>0) board[x][y] = '0' + count;
        else{
            board[x][y] = 'B'; 
            for(auto d : dirs) dfs(board, x + d[0], y + d[1]);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        if(board[r][c] == 'M'){
            board[r][c]= 'X'; return board;
        }
        
        dfs(board, r, c);
        return board;
    }
};
