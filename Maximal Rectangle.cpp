class Solution {
public:
    vector<int> psefun(vector<int>& prefixsum){
        int n = prefixsum.size();
        vector<int> res(n);
        stack<int> st;
        for(int i(0);i < n;i++){
            while(!st.empty() && prefixsum[st.top()] >= prefixsum[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> nsefun(vector<int>& prefixsum){
        int n = prefixsum.size();
        vector<int> res(n);
        stack<int> st; 

        for(int i(n-1);i >= 0;i--){
            while(!st.empty() && prefixsum[st.top()] >= prefixsum[i]) st.pop();

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    int hist(vector<int>& prefixsum){
        // find nse and pse hehe remember this approach plis
        vector<int>nse = nsefun(prefixsum);
        vector<int>pse = psefun(prefixsum);
        int maxi = INT_MIN;
        int n = prefixsum.size();
        for(int i(0);i < n;i++){
            maxi = max(maxi , prefixsum[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans(0);
        vector<vector<int>> prefixsum(n, vector<int>(m, 0));

        for(int j(0);j < m;j++){
            int sum = 0;
            for(int i = 0;i < n;i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0') sum = 0;
                prefixsum[i][j] = sum;
            }
        }

        for(int i(0);i < n;i++){
            ans = max(ans , hist(prefixsum[i]));
        }
        return ans;
    }
};
