class Solution {
public:
    string decToBinary(int n) {
        string bin = "";
        
        while (n > 0) {
    		int bit = n % 2;
          	bin.push_back('0' + bit);
            n /= 2;
        }
    
    	reverse(bin.begin(), bin.end());
        return bin;
    }
    int countMonobit(int n) {
        int ans(0);
        
        for(int i(0);i <= n;i++){
            string x = decToBinary(i);
            bool k = true;
            for(int j(1);j < x.length();j++){
                if(x[j] == x[j - 1]) continue;
                else{
                    k = false; break;
                }
            }
            if(k) ans++;
        }

        return ans;
    }
};
