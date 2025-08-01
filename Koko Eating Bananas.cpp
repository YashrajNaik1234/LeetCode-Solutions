class Solution {
public:
    int calTotalHours(vector<int>& piles, int mid){
        int hours(0);
        
        for(int i(0);i < piles.size();i++){
           hours += (piles[i] + mid - 1) / mid;
        }

        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low(1), high(*max_element(piles.begin(),piles.end()));
        int ans(high);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int hours = claTotalHours(piles, mid);
            if (hours <= h)
                ans = mid , high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};
