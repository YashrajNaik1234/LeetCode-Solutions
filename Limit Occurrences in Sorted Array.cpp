class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;

        for(auto i:nums){
            mp[i]++;
            if(mp[i] > k) continue;
            else ans.push_back(i);
        }

        return ans;
    }
};
