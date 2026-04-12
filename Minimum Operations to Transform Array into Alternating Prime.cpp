class Solution {
public:
    static const int X = 2e5;
    bool prime[X];
    
    void sieve() {
        fill(prime, prime + X, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < X; i++) {
            if (prime[i]) {
                for (int j = i * i; j < X; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        sieve(); int ans(0);
        for(int i(0);i < nums.size();i++){
            int val = nums[i];
            if(i % 2 == 0){
                if(!prime[val]){
                    while(!prime[val++]) ans++;
                }
            }
            else{
                if(val == 2) ans++;
                if(prime[val]) ans++;
            }
        }

        return ans;
    }
};
