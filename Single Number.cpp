#pragma optimization (Ofast)
#pragma GCC optimization ("unroll-loops")
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans(0);
        for(auto i : nums) ans ^= i;
        return ans;
    }
};
