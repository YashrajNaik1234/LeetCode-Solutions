class Solution {
public:
    int gcd(int a, int b) {
       if (b == 0) return a;
       return gcd(b, a % b);
    }

    int getScore(vector<int>& arr){
        int m = arr.size();
        if(m <= 0) return 0;

        vector<int> pref(m), suff(m);

        pref[0] = arr[0];
        for(int i(1); i < m; i++){
            pref[i] = gcd(pref[i - 1], arr[i]);
        }

        suff[m - 1] = arr[m - 1];
        for(int i(m - 2); i >= 0; i--){
            suff[i] = gcd(suff[i + 1], arr[i]);
        }

        int res(0);
        for(int i(0);i < m ;i++){
            if(pref[i] == suff[i]) res++;
        }

        return res;
    }
    
    int maxValidSplits(vector<int>& nums) {
        int n(nums.size()), mx = max(0, getScore(nums));

        vector<int> arr(n - 1);
        for(int i(0);i < n;i++){
            arr.clear();
            for(int j(0);j < n;j++){
                if(i == j) continue; arr.push_back(nums[j]);
            }

            mx = max(mx, getScore(arr));
        }

        return max(mx - 1, 0);
    }
};
