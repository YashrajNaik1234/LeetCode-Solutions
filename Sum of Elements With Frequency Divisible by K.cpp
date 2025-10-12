class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum(0);
        
        map<int,int> mp;
        for(auto i:nums) mp[i]++;

        for(auto i:mp){
            if(i.second % k == 0) sum += i.first * i.second;
        }
        return sum;
    }
};
