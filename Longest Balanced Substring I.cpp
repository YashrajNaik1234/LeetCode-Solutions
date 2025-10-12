class Solution {
public:
    bool check(vector<int> arr){
        int cnt(0);
        for(auto i:arr){
            if(i > 0){
                if(cnt == 0) cnt = i;
                else if(cnt != i) return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length(),maxLen = 0;

        for(int i(0);i < n;i++){
            vector<int> freq(26, 0);
            for(int j(i);j < n;j++){
                freq[s[j] - 'a']++;
                if(check(freq)) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
