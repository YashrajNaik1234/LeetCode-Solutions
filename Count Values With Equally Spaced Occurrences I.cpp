class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans(0),n(nums.size());

        for(int i(1);i < 101;i++){
            vector<int> p;

            for(int j(0);j < n;j++) if(nums[j] == i) p.push_back(j);
            if(p.size() == 3 and p[1] - p[0] == p[2] - p[1]) ans++;
        }

        return ans;
    }
};
