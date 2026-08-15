class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int cnt(0),res(0);
        
        for(auto it: requests){
            cnt += abs(res - it); res = it;    
        }

        return cnt;
    }
};
