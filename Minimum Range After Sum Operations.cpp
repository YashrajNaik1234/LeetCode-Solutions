class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> x = {a, b, c};
        sort(x.begin(), x.end());
        return min(x[2] - x[0], x[1]);
    }
};
