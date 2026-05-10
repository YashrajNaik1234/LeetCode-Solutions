class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(auto i : chunks) s += i;

        auto solve = make_pair(chunks, queries);
        auto isLetter = [&](char c){
            return c >= 'a' and c <= 'z';
        };
        
        unordered_map<string, int> freq;
        int n(s.length()), i(0);
        while(i < n){
            if(!isLetter(s[i])){
                i++; continue;
            }

            int st = i;
            string w = "";

            while(i < n){
                if(isLetter(s[i])){
                    w += s[i]; i++;
                }
                else if(s[i] == '-' and i - 1 >= st and i + 1 < n and 
                    isLetter(s[i - 1]) and isLetter(s[i + 1])){
                    w += s[i]; i++;
                }
                else break;
            } freq[w]++;
        }

        vector<int> ans;
        for(auto i: queries) ans.push_back(freq[i]);
        return ans;
    }
};
