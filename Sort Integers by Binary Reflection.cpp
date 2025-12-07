class Solution {
public:
    int reflect(int x) {
        int rev = 0;
        while (x > 0) {
            rev = (rev << 1) | (x & 1); x >>= 1;
        }
        return rev;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = reflect(a), rb = reflect(b);
            if(ra == rb) return a < b;
            return ra < rb;
        });
        return nums;
    }
};
