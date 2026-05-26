class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> sChar(26, 0), cChar(26, 0);
        for(auto i:word){
            if(i > 'Z') sChar[i - 'a']++;
            else cChar[i - 'A']++;
        }

        int ans(0);
        for(int i(0);i < 26;i++){
            if(sChar[i] > 0 and cChar[i] > 0) ans++;
        }

        return ans;
    }
};
