class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps(0),l(0),r(0);

        while(r < nums.size() - 1){
            int x(INT_MIN);
            for(int i(l);i <= r;i++) x = max(x, i + nums[i]);
            if(x == r) return -1;

            jumps++; l = r + 1; r = x;
        }

        return jumps;
    }
};
