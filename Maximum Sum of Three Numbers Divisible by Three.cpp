class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int sum(0);

        vector<int> x0,x1,x2;
        for(auto i:nums){
            if(i % 3 == 0) x0.push_back(i);
            if(i % 3 == 1) x1.push_back(i);
            if(i % 3 == 2) x2.push_back(i);
        }

        sort(x0.begin(),x0.end());
        sort(x1.begin(),x1.end());
        sort(x2.begin(),x2.end());

        int x0s = x0.size(),x1s = x1.size(), x2s = x2.size();
        int ans1 = (x0s >= 3) ? x0[x0s - 1] + x0[x0s - 2] + x0[x0s - 3] : 0;
        int ans2 = (x0s >= 1 and x1s >= 1 and x2s >= 1) ? x0[x0s - 1] + x1[x1s - 1] + x2[x2s - 1] : 0;
        int ans3 = (x1s >= 3) ? x1[x1s - 1] + x1[x1s - 2] + x1[x1s - 3] : 0;
        int ans4 = (x2s >= 3) ? x2[x2s - 1] + x2[x2s - 2] + x2[x2s - 3] : 0;

        return max({ans1, ans2, ans3, ans4});
    }
};
