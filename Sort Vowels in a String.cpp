class Solution {
public:
    string sortVowels(string s) {
        vector<char> c;

        for(auto i:s){
            if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'
            or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U') c.push_back(i);
        }

        sort(c.begin(),c.end()); int j(0);
        for(auto &i:s){
            if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'
            or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U') i = c[j++];
        }
        return s;
    }
};
