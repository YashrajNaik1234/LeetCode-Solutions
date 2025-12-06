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
    bool isPalindrome(string S) {
        string P = S;
        reverse(P.begin(), P.end());

        if (S == P) return true;
        else return false;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for (auto i : nums) {
            if(isPalindrome(decToBinary(i))){
                ans.push_back(0); continue;
            }
            int x(0);
            while(!isPalindrome(decToBinary(i - x)) and !isPalindrome(decToBinary(i + x))) x++;
            ans.push_back(x);
        }
        return ans;
    }
};
