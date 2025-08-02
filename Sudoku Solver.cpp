#define fr(i, a, b) for (int i(a); i < b; i++)
class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board, char c) {
        for (int k(0); k < 9; k++) {
            if (board[i][k] == c)
                return false;
            if (board[k][j] == c)
                return false;
            if (board[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == c)
                return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board) {
        fr(i, 0, 9) {
            fr(j, 0, 9) {
                if (board[i][j] == '.') {
                    for (auto k = '1'; k <= '9'; k++) {
                        if (isValid(i, j, board, k)) {
                            board[i][j] = k;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
