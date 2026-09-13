class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> p;
        for(int i(0);i < nums.size();i++){
            p[nums[i]].push_back(i);
        }

        int ans(0);
        for(auto [x, it]: p){
            if(it.size() < 3) continue;

            int diff(it[1] - it[0]);
            bool k = true;

            for(int j(2);j < it.size();j++){
                if(it[j] - it[j - 1] != diff){
                    k = false; break;
                }
            }

            if(k) ans++;
        }

        return ans;
    }
};
