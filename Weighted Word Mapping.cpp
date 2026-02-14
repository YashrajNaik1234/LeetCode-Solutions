class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string results = "";
        
        for(auto i:words){
            int sum = 0;
            for(auto c:i){
                sum += weights[c - 'a'];
            }

            results += (char)('z' - sum % 26);
        }

        return results;
    }
};
