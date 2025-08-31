class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s(friends.begin(), friends.end());
        vector<int> result;

        for (int id : order) {
            if (s.count(id)) {
                result.push_back(id);
            }
        }
        return result;
    }
};©leetcode
