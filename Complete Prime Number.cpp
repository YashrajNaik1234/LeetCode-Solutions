class Solution {
public:
    bool completePrime(int num) {
        const int X = 32767;
        int prime[X];
        vector<int> prime_numbers;
        for (int i = 2; i < X; i++) prime[i] = i;
        for (int i = 2; i < X; i++) {
            if (prime[i] == i) {
                prime_numbers.push_back(i);
                for (int j = i * i; j < X; j += i) if (prime[j] == j) prime[j] = i;
            }
        }

        string s = to_string(num);
        string x = "";
        for(int i(0);i < s.length();i++){
            x += s[i];
            if(find(prime_numbers.begin(),prime_numbers.end(),stoi(x)) == prime_numbers.end()) return false;
        }

        x = "";
        for(int i(s.length() - 1);i >= 0;i--){
            reverse(x.begin(),x.end()); x += s[i]; reverse(x.begin(),x.end());
            if(find(prime_numbers.begin(),prime_numbers.end(),stoi(x)) == prime_numbers.end()) return false;
        }

        return true;
    }
};©leetcode
