class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        
        for(auto i: words){
            if(i.length() >= k) cnt[i.substr(0, k)]++;
        }

        int ans(0);
        for(auto [i, x]: cnt){
            if(x >= 2) ans++;
        }

        return ans;
    }
};
