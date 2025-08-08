class Solution {
public:
    bool canChange(string start, string target) {
        int i(0),j(0);

        while(i < start.size() or j < start.size()){
            while(i < start.size() and start[i] == '_') i++;
            while(j < start.size() and target[j] == '_') j++;

            if(i == start.size() or j == start.size()) break;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L') if(i < j) return false;
            if(start[i] == 'R') if(i > j) return false;
            i++; j++;
        }

        return i == start.size() and j == start.size();
    }
};
