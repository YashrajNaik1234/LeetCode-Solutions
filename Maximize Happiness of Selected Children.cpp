class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans(0);
        sort(happiness.rbegin(),happiness.rend());
        for(int i(0);i<k;i++){
            long long cnt = max(happiness[i] - i, 0); ans+=cnt;
        }
        return ans;
    }
};
