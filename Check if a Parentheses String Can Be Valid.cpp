class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1) return 0;

        stack<int> openB,unlock;
        for(int i(0);i < s.size();i++){
            if(locked[i] == '0') unlock.push(i);
            else if(s[i] == '(') openB.push(i);
            else if(s[i] == ')'){
                if(!openB.empty()) openB.pop();
                else if(!unlock.empty()) unlock.pop();
                else return false;
            }
        }

        while(!openB.empty() and !unlock.empty() and openB.top() < unlock.top()){
            openB.pop(); unlock.pop();
        }

        if(!openB.empty()) return false;

        return true;
    }
};
