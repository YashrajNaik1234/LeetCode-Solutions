class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum(0); bool k(1);
        for(auto i: nums){
            if(k) sum += i; else sum -= i;
            k = !k;
        }

        return sum;
    }
};©leetcode
