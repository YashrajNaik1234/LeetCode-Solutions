class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> st;
        long long res = 0;

        for(auto i: nums){
            while(!st.empty() and st.back() < i){
                res++; st.pop_back();
            }

            if(!st.empty()) res++; st.push_back(i);
        }

        if(res - (n - 1) < 0) return 0;
        return res - (n - 1);
    }
};©leetcode
