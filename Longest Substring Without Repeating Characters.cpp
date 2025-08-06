class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int left = 0, right = 0, maxLen = 0, currLen = 0;

        while (right < s.length()) {
            if (hash.find(s[right]) != hash.end()) {
                if (hash[s[right]] >= left) left = hash[s[right]] + 1;
            }

            currLen = right - left + 1;
            maxLen = max(maxLen, currLen);

            hash[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};
