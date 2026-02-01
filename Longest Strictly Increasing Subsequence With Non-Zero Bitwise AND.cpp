class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans(0);
        
        for(int i(0);i <= 30;i++){
            vector<int> x;
            for(auto it:nums) if(it & (1 << i)) x.push_back(it);
            if(x.empty()) continue;
            
            vector<int> y; cout << i << "  ";
            for(auto it:x){
                auto itx = lower_bound(y.begin(),y.end(),it);
                if(itx == y.end()) y.push_back(it);
                else *itx = it;
                for(auto x: y) cout << x << " "; cout << endl;
            }

            ans = max(ans, (int)y.size());
        }

        return ans;
    }
};
