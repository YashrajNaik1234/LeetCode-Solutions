class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, int k, string word) {
        if (k == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '?';

        if (solve(board, i + 1, j, k + 1, word) or
            solve(board, i, j + 1, k + 1, word) or
            solve(board, i - 1, j, k + 1, word) or
            solve(board, i, j - 1, k + 1, word))
            return true;

        board[i][j] = temp;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans(0);

        for (int i(0); i < board.size(); i++) {
            for (int j(0); j < board[0].size(); j++) {
                if (solve(board, i, j, 0, word))
                    return 1;
            }
        }
        return false;
    }
};
