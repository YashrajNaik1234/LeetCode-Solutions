#pragma optimization(Ofast)
#pragma GCC optimization("unroll-loops")
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> next;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();

            next[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        for (int num : nums1) ans.push_back(next[num]);

        return ans;
    }
};
