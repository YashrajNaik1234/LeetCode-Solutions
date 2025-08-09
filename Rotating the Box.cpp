class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans(box[0].size(), vector<char>(box.size(), '.')); 

        for (int i = 0; i < box.size(); i++) {
            int minIndex = box[0].size() - 1; 
            for (int j = box[0].size() - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    ans[minIndex][box.size() - i - 1] = '#';
                    minIndex--;
                }
                if (box[i][j] == '*') {
                    minIndex = j - 1; 
                    ans[j][box.size() - i - 1] = '*';
                }
            }
        }
        return ans;
    }
};
