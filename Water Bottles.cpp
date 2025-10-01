class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans(0) , carr(0);

        while(numBottles != 0){
            ans += numBottles; numBottles += carr;
            carr = (numBottles % numExchange); numBottles /= numExchange; 
        }

        return ans;
    }
};
