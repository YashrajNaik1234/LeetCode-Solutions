class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans(0);
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        for(int i(0);i < nums.size() - 2;i++){
            int k = i + 2;
            for(int j(i + 1);j < nums.size() - 1 and nums[i] != 0;j++){
                while(k < nums.size() and nums[i] + nums[j] > nums[k]){
                    k++; ans += k - j - 1;
                }
            }
        }

        return ans;
    }
};
