class Solution {
public:
    string fractionToDecimal(int nume, int dene) {
        if(nume == 0) return "0";

        string res = "";
        if((nume < 0) ^ (dene < 0)) res += "-";

        long long num  = llabs((long long)nume);
        long long den  = llabs((long long)dene);

        res += to_string(num / den);
        long long rem = num % den;
        if(rem == 0) return res;

        res += ".";
        unordered_map<int,int> mp;
        while(rem != 0){
            if(mp.count(rem)){
                res.insert(mp[rem], "("); res += ")"; break;
            }

            mp[rem] = res.size(); rem *= 10;
            res += to_string(rem / den); rem %= den;
        }

        return res;
    }
};
