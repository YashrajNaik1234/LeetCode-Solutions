class Solution {
public:
    int minBitFlips(int start, int goal) {
        string first(bitset<32>(start).to_string());
        string last(bitset<32>(goal).to_string());
        int ans(0);

        for(int i(0) ; i < first.size();i++){
            if(first[i] != last[i]) ans++;
        }

        return ans;
    }
};
