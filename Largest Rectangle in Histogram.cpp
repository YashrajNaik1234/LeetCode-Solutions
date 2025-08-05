class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans(0); stack<int> st;

        for(int i(0);i < heights.size();i++){
            while(!st.empty() and heights[i] < heights[st.top()]){
                int ele = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                ans = max(ans, heights[ele] * (i - pse - 1));
            } st.push(i);
        }

        while(!st.empty()) {
            int ele = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, heights[ele] * ((int)heights.size() - pse - 1));
        }

        return ans;
    }
};
