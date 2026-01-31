class Solution {
public:
    string reverseByType(string s) {
        vector<char> sp,ch;
        for(auto i:s){
            if(i >= 'a' and i <= 'z') ch.push_back(i);
            else sp.push_back(i);
        }

        reverse(sp.begin(),sp.end());
        reverse(ch.begin(),ch.end());

        int it1(0),it2(0);
        for(auto &i:s){
            if(i >= 'a' and i <= 'z') i = ch[it1++];
            else i = sp[it2++];
        }

        return s;
    }
};
