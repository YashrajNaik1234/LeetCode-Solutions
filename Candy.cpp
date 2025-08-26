class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum(1),i(1);

        while(i < ratings.size()){
            if(i < ratings.size() and ratings[i] == ratings[i - 1]){
                sum++; i++; continue;
            }
            
            int peak(1);
            while(i < ratings.size() and ratings[i] > ratings[i - 1]){
                peak++; sum += peak; i++;
            }

            int down(1);
            while(i < ratings.size() and ratings[i] < ratings[i - 1]){
                sum += down; i++; down++;
            }

            if(down > peak){
                sum += down - peak;
            }
        }

        return sum;
    }
};
