class Solution {
public:
    int calTotalDays(vector<int>& v, int mid){
        int days(1),load(0);
        
        for(int i(0);i < v.size();i++){
           if(v[i] + load > mid){
                days++; load = v[i];
           }
           else load += v[i];
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low(*max_element(weights.begin(),weights.end()));
        int high(accumulate(weights.begin(),weights.end(),0));
        int ans(high);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int day = calTotalDays(weights, mid);
            if (day <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
