class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        
        unordered_set<int> st;
        unordered_map<int, int> mp;

        int sum(0),left(0);
        for(int i(0);i < nums.size();i++){
            int num = nums[i];
            if(mp[num] == 0){
                st.insert(num); sum += num;
            } mp[num]++;

            while(sum >= k){
                ans = min(ans, i - left + 1);
                int leftnum = nums[left];
                mp[leftnum]--;

                if(mp[leftnum] == 0){
                    st.erase(leftnum); sum -= leftnum;
                } left++;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
