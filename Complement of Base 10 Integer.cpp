class Solution {
public:
    int bitwiseComplement(int n) {
        int k(n), m(0);
        if(k == 0) return 1;

        while(k != 0){
            m = (m << 1) | 1; k = k >> 1;
        }
        
        return (~n) & m;
    }
};
