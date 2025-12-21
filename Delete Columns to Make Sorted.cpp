class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans(0);

        for(int i(0);i < strs[0].size();i++){
            bool k(1);
            for(int j(1);j < strs.size();j++){
                if(strs[j][i] < strs[j - 1][i]){
                    k = 0 ; break;
                }
            }

            ans += (!k);
        }

        return ans;
    }
};
