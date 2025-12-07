class Solution {
public:
    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        return isPrime;
    }
    int largestPrime(int n) {
        vector<bool> isPrime = sieveOfEratosthenes(n);
        vector<int> prime_numbers;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) prime_numbers.push_back(i);
        }
        int ans(0), i(0), res(0);
        if(n < 2) return res;
        while (ans + prime_numbers[i] <= n) {
            ans += prime_numbers[i]; 
            if(i + 1 < prime_numbers.size()) i++;
            if (find(prime_numbers.begin(), prime_numbers.end(), ans) != prime_numbers.end()) res = ans;
        }
        return res;
    }
};
