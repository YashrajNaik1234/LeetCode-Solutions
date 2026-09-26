class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sumS(0),sumT(0);

        for(auto i: source) sumS += i;
        for(auto i: target) sumT += i;

        return sumS == sumT;
    }
};
