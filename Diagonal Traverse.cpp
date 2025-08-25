class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i(0),j(0),k(0);
        vector<int> ans;

        while(i < mat.size()){
            int x1(i), x2(j); vector<int> x;
            while(x1 >= 0 and x2 < mat[0].size()){
                x.push_back(mat[x1][x2]); x1--; x2++;
            }

            if(k) reverse(x.begin(),x.end());
            for(auto h: x) ans.push_back(h);

            i++; k ^= 1;
        } j++; i--;

        while(j < mat[0].size()){
            int x1(i), x2(j); vector<int> x;
            while(x1 >= 0 and x2 < mat[0].size()){
                x.push_back(mat[x1][x2]); x1--; x2++;
            }

            if(k) reverse(x.begin(),x.end());
            for(auto h: x) ans.push_back(h);

            j++; k ^= 1;
        }

        return ans;
    }
};
