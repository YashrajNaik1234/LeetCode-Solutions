class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto i: nums) if(i % 2 == 0) mp[i]++;
        for(auto i: nums) if(mp[i] == 1) return i;

        return -1;
    }
};
