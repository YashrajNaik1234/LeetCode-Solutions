class Solution {
public:
    vector<int> next_right(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] >= a[st.top()]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> next_left(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] < a[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    long long bowlSubarrays(vector<int>& nums) {
        vector<int> right = next_right(nums), left = next_left(nums);

        int ans(0);
        for(int i(0);i < nums.size();i++){
            if(left[i] != -1 and left[i] < i and right[i] > i) ans++;
        }

        return ans;
    }
};
