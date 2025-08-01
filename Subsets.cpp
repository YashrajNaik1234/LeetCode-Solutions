class Solution {
public:
    void calcSubset(vector<int>& a, vector<vector<int>>& res,
                    vector<int>& subset, int index) {
        res.push_back(subset);
        for (int i(index); i < a.size(); i++) {
            subset.push_back(a[i]);
            calcSubset(a, res, subset, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> sets(vector<int>& a) {
        vector<int> subset;
        vector<vector<int>> res;
        int index = 0;
        calcSubset(a, res, subset, index);
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(sets(nums));
        return ans;
    }
};
