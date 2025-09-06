class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string begin;
public:
    void dfs(string word, vector<string>& seq){
        if(word == begin){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq); 
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];
        for (int i(0); i < begin.size(); i++) {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mp.find(word) != mp.end() and mp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1; begin = beginWord;

        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return ans;
        int sz = beginWord.size(); st.erase(beginWord);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string word = q.front(); q.pop();
                int steps = mp[word];
                if(word == endWord) break;
                for (int i(0); i < sz; i++) {
                    char org = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (st.find(word) != st.end()) {
                            q.push(word); st.erase(word); mp[word] = steps + 1;
                        }
                    }
                    word[i] = org;
                }
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }

        return ans;
    }
};
