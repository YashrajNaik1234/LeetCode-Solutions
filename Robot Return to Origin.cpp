class Solution {
public:
    bool judgeCircle(string moves) {
        int u(0) , d(0) , l(0) , r(0);
        for(auto i:moves){
            if(i == 'L') l++;
            if(i == 'R') r++;
            if(i == 'U') u++;
            if(i == 'D') d++;
        }

        if(u == d and r == l) return true;
        return false;
    }
};
