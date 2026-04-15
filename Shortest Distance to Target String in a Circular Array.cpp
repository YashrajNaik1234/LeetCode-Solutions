class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = words.size();

        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, (int)words.size() - dist));
            }
        }

        return ans < words.size() ? ans : -1;
    }
};
