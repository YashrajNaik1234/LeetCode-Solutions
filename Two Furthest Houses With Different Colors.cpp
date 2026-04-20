class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans(0);

        for(int i(0);i < colors.size();i++){
            int j(colors.size() - 1);
            while(j >= i){
                if(colors[i] != colors[j]) ans = max(ans, abs(i - j)); j--;
            }
        }

        return ans;
    }
};
