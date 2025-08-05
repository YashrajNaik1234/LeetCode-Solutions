class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i(0);i < num.size();i++){
            while(k > 0 and !st.empty() and st.top() > num[i]){
                st.pop(), k--;
            }
            st.push(num[i]);
        }

        while(k > 0) st.pop(), k--;
        if(st.empty()) return "0";

        string ans = "";
        while(!st.empty()) ans += st.top(), st.pop();

        while(ans.size() != 0 and ans.back() == '0') ans.pop_back();
        if(ans.size() == 0) return "0";

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
