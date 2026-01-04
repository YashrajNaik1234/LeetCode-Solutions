class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long eq(0),neq(0);
        for(int i(0);i < s.length();i++){
            if(s[i] != t[i]){
                if(s[i] == '0') eq++; else neq++;
            }
        }

        long long res(0), mini(min(eq, neq));
        res += min((long long)swapCost,2ll * flipCost) * mini;
        eq -= mini, neq -= mini;

        int rem(eq + neq);
        if(rem > 0){
            long long sum = min(2ll * flipCost, (long long)swapCost + (long long)crossCost);
            res += sum * (rem / 2); if(rem % 2) res += flipCost;
        }

        return res;
    }
};
