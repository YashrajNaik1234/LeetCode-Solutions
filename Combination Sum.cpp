class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int n,vector<int>& v,int sum,int tar,vector<int>& res){
        if(i == n){
            if(sum == tar) ans.push_back(res); return;
        }

        if(sum + v[i] <= tar){
            res.push_back(v[i]);
            solve(i,n,v,sum + v[i],tar,res);
            res.pop_back();
        }
        solve(i + 1,n,v,sum,tar,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        solve(0,candidates.size(),candidates,0ll,target,res);
        return ans;
    }
};
