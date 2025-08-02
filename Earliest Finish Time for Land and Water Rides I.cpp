class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); ++i) {
            int lf = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); ++j) {
                int ws = max(waterStartTime[j], lf);
                int wf = ws + waterDuration[j];
                ans = min(ans, wf);
            }
        }

        for (int j = 0; j < waterStartTime.size(); ++j) {
            int wf = waterStartTime[j] + waterDuration[j];

            for (int i = 0; i < landStartTime.size(); ++i) {
                int ls = max(landStartTime[i], wf);
                int lf = ls + landDuration[i];
                ans = min(ans, lf);
            }
        }

        return ans;
    }
};
