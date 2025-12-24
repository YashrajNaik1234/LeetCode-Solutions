class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());

        int val(0);
        for(int i(0);i < capacity.size();i++){
            val += capacity[i];
            if(val >= sum) return i + 1;
        }

        return capacity.size();
    }
};
