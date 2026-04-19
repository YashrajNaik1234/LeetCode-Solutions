class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int i, j;

        for (i = 0, j = 0; i < a.size() && j < b.size(); j++)
            i += a[i] > b[j];

        return max(0, j - i - 1);
    }
};
