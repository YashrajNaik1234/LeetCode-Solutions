#define fr(i,a,b) for(int i(a);i < b;i++)

class Solution
{
public:
    bool isSafe(int x, int y, vector<string> v){
        fr(i,0,x){
            if(v[i][y] == 'Q') return false;
        }

        int r(x),c(y);
        while(r >= 0 and c >= 0){
            if(v[r--][c--] == 'Q') return false;
        }

        r = x, c = y;
        while(r >= 0 and c < v.size()){
            if(v[r--][c++] == 'Q') return false;
        }

        return true;
    }

    void solve(int i, vector<vector<string>>& ans, vector<string> v){
        if(i >= v.size()){
            ans.push_back(v); return;
        }

        if(i < 0 or i >= v.size()) return;

        fr(k,0,v.size()){
            if(isSafe(i, k, v)){
                v[i][k] = 'Q';
                solve(i + 1, ans, v);
                v[i][k] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string x = ""; fr(i,0,n) x += '.';
        vector<string> y(n, x);
        solve(0, ans, y);
        return ans;
    }
};
