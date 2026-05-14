class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> mp(*max_element(nums.begin(), nums.end()) + 1, 0);
        for(auto i:nums) mp[i]++;

        if(mp[mp.size() - 1] != 2) return false;
        for(int i(1);i < mp.size() - 1;i++){
            if(mp[i] != 1) return false;
        }

        return true;
    }
};
