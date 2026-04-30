class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum(0), prev(0);
        for(int x: nums){
            sum += max(0ll, prev - x); prev = x;
        }

        return sum;
    }
};
