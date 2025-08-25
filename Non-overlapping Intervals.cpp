class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int ans(0), prev = interval[0][1];
        for(int i(1);i < interval.size();i++){
            if(prev > interval[i][0]) ans++;
            else prev = interval[i][1];
        }

        return ans;
    }
};
