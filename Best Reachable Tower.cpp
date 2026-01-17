class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans(2, -1); int x(-1);
        for(auto i:towers){
            if(abs(center[0] - i[0]) + abs(center[1] - i[1]) <= radius){
                if(i[2] > x or (i[2] == x and (i[0] < ans[0] or (i[1] == ans[0] and i[1] < ans[1])))){
                    x = i[2]; ans = {i[0], i[1]};
                }
            }
        }

        return ans;
    }
};
