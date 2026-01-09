class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        vector<string> ans;
        unordered_map<char, int> mp;

        for(auto it: s1) mp[it] = 1;
        for(auto it: s2) mp[it] = 2;
        for(auto it: s3) mp[it] = 3;

        for(string s:words){
            int row1 = mp[tolower(s[0])];
            bool flag = true;
            for(char ch:s){
                if(mp[tolower(ch)] != row1){
                    flag = false; break;
                }
            }

            if(flag) ans.push_back(s);
        }
        
        return ans;
    }
};
