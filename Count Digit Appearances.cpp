class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans(0);
        for(auto i:nums){
            while(i != 0){
                (i % 10 == digit) ? ans++ : ans; i /= 10;
            }
        }

        return ans;
    }
};
