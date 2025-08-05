class Solution {
public:
    vector<int> findPse(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i(0);i < arr.size();i++){
            while(!st.empty() and arr[i] <= arr[st.top()]) st.pop();
            ans[i] = st.empty() ? -1 : st.top(); st.push(i);
        }
        
        return ans;
    }

    vector<int> findNse(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i(arr.size() - 1); i >=0 ;i--){
            while(!st.empty() and arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty() ? arr.size() : st.top(); st.push(i);
        }
        
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long MOD = 1e9 + 7;
        int ans(0);

        for(int i(0);i < arr.size();i++){
            ans = (ans + ((nse[i] - i) * (i - pse[i])) % MOD * arr[i] * 1ll) % MOD;
        }

        return ans;
    }
};
