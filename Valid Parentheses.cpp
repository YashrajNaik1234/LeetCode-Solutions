class Solution {
public:
    bool isValid(string s){
        if(s.length() & 1) return false;

        stack<char> st;
        for(int i(0);i < s.length();i++){
            if(s[i] == '(' or s[i]  == '{' or s[i] == '[') st.push(s[i]);
            else{
                if(st.size() == 0) return false;

                if((st.top() == '(' and s[i] == ')')
                or (st.top() == '[' and s[i] == ']')
                or (st.top() == '{' and s[i] == '}'))
                    st.pop();
                else return false;
            }
        }

        if(st.size() == 0) return true;
        else return false;
    }
};
