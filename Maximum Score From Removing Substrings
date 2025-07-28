class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if(y > x) swap(x, y), reverse(s.begin(),s.end());
        
        int cntA(0),cntB(0),totalPoints(0);
        for(auto i:s){
            if(i == 'a') cntA++;
            else if(i == 'b'){
                if(cntA > 0){
                    cntA--; totalPoints += x;
                }
                else cntB++;
            }
            else{
                totalPoints += min(cntB, cntA) * y;
                cntA = cntB = 0;
            }
        }

        totalPoints += min(cntA, cntB) * y;
        return totalPoints;
    }
};
