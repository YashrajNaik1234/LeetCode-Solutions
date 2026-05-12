class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int sum(0),cnt(0),i(0);
        while(i < events.size() and cnt < 10){
            if(events[i].length() == 1){
                if(events[i] == "W") cnt++;
                else sum += events[i][0] - '0'; 
            }
            else sum++; i++;
        }

        return {sum, cnt};
    }
};
