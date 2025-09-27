class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        map<int, vector<char>> freqx;
        for (auto& [ch, count] : freq) freqx[count].push_back(ch);

        int maxSize = 0;
        int selectFreq = 0;

        for (auto& [count, chars] : freqx) {
            int groupSize = chars.size();
            if (groupSize > maxSize ||
                (groupSize == maxSize && count > selectFreq)) {
                maxSize = groupSize; selectFreq = count;
            }
        }

        string result;
        for (char c : freqx[selectFreq]) result += c;

        return result;
    }
};©leetcode
