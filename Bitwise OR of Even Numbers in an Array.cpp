class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int x(0);
        for(auto i:nums) if(!(i & 1)) x |= i;
        return x;
     }
};©leetcode
