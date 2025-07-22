class Solution {
public:
    void solve(string d,vector<string>& mp,vector<string>& ans,int index,string s){
        if(index >= d.size()){
            ans.push_back(s); return;
        }

        int x = d[index] - '0';
        string val = mp[x];
        for(int i(0);i < val.size();i++){
            s.push_back(val[i]);
            solve(d, mp, ans, index + 1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, mp, ans, 0, "");
        return ans;
    }
};
