class Solution {
public:
    long long maxPoints(vector<int>& tech1, vector<int>& tech2, int k) {
        int n = tech1.size(); long long res(0);

        vector<int> v(n);
        for(int i(0);i < n;i++){
            res += tech2[i]; v[i] = tech1[i] - tech2[i];
        }

        sort(v.begin(),v.end(),greater<int>());
        for(int i(0);i < k;i++) res += v[i];
        for(int i(k);i < n;i++) if(v[i] > 0) res += v[i]; else break;
        return res;
    }
};
