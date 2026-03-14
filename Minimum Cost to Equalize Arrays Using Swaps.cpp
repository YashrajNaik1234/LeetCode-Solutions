class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> x = {nums1, nums2};
        unordered_map<int,int> total, res;

        for(auto i: nums1) total[i]++, res[i]++;
        for(auto i: nums2) total[i]++;
        for(auto i: total) if(i.second % 2) return -1;
        
        int ans = 0;
        for(auto i: res){
            int n = total[i.first] / 2;
            if(i.second > n) ans += i.second - n;
        }

        return ans;
    }
};
