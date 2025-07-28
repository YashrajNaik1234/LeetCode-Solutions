class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = "#";
        for(char c: s){
            s1 += c; s1 += "#";
        }

        int n = s1.length();
        vector<int> p_radii(n); p_radii[0] = 0;
        int centre(0),r(0),l(0),maxlen(0);

        for(int i(1);i < n;i++){
            int k = 0;

            if(i > r) k = 0;
            else{
                int j = l + (r - i);
                if(j - p_radii[j] > l){
                    p_radii[i] = p_radii[j]; continue;
                }
                else k = r - i;
            }

            while(i - k >= 0 and i + k < n and s1[i - k] == s1[i + k]) k++;
            k--; p_radii[i] = k;

            if(p_radii[i] > maxlen){
                maxlen = p_radii[i]; centre = i;
            }

            if(i + k > r){
                l = i - k; r = i + k;
            }
        }

        return s.substr((centre / 2) - (maxlen / 2), maxlen);
    }
};
