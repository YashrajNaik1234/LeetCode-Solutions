class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans(0);

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string& str1 = words[i]; string& str2 = words[j];

                if (str1.size() > str2.size()) continue;
                if (str2.find(str1) == 0 && str2.rfind(str1) == str2.size() - str1.size()) ans++;
            }
        }

        return ans;
    }
};
