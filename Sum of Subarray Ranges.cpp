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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long ans(0);

        for(int i(0);i < arr.size();i++){
            ans += 1ll * (nse[i] - i) * (i - pse[i]) * arr[i];
        }

        return ans;
    }

    vector<int> findPge(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i(0);i < arr.size();i++){
            while(!st.empty() and arr[i] >= arr[st.top()]) st.pop();
            ans[i] = st.empty() ? -1 : st.top(); st.push(i);
        }
        
        return ans;
    }

    vector<int> findNge(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i(arr.size() - 1); i >=0 ;i--){
            while(!st.empty() and arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty() ? arr.size() : st.top(); st.push(i);
        }
        
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = findNge(arr);
        vector<int> pge = findPge(arr);
        long long ans(0);

        for(int i(0);i < arr.size();i++){
            ans += 1ll * (nge[i] - i) * (i - pge[i]) * arr[i];
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini = sumSubarrayMins(nums);
        long long maxi = sumSubarrayMaxs(nums);
        return maxi - mini;
    }
};
