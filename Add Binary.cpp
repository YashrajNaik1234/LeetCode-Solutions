class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long op1 = 0;
            long long op2 = 0;
            int j = i;
            bool ok = 0;
            while(j<n && colors[i]==colors[j]){
                if(ok) op2+=nums[j];
                else op1+=nums[j];
                j++;
                ok=!ok;
            }

            i = j-1;
            ans+=max(op1,op2);
        }

        return ans;
    }
};
