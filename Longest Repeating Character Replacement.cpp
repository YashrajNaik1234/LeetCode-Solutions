class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int left(0),right(0),maxLen(0),maxFreq(0);
        vector<int> mp(26,0);

        while(right < s.length()){
            mp[s[right] - 'A']++;
            maxFreq = max(maxFreq, mp[s[right] - 'A']);

            int window(right - left + 1);
            if(window - maxFreq > k){
                mp[s[left] - 'A']--; left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
