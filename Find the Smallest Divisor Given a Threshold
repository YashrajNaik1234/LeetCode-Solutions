class Solution {
public:
    int sumByD(vector<int>& v, int mid){
        int sum(0);
        
        for(int i(0);i < v.size();i++){
           sum += (v[i] + mid - 1) / mid;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low(1), high(*max_element(nums.begin(),nums.end()));

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int sum = sumByD(nums, mid);
            if (sum <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
