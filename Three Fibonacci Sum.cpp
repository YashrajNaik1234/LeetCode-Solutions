class Solution {
public:
    bool solve(int n) {
        int a = 0, b = 1, c = 1;

        while(true){
            if(c == n) return true;
            else if(c > n) return false;

            int temp = b + c;
            a = b; b = c; c = temp;
        }
        return false;
    }

    bool threeFibonacciSum(int n) {
        if(n % 2 != 0) return false;
        else if(solve(n/2)) return true;
        
        return false;
    }
};
