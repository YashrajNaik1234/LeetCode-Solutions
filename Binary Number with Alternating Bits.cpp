class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n & 1 ; n >>= 1 ;
        while (n){
            int bit = n & 1 ;
            if (prevBit == bit) return false ;
            prevBit = bit ; n >>= 1 ;
        }
        return true ;
    }
};
