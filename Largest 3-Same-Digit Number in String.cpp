class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i(0);i < num.length() - 2;i++){
            if(num[i] == num[i + 1] and num[i] == num[i + 2]){
                if(ans == "") ans = num.substr(i, 3);
                else{
                    if(num[i] - '0' > ans[0] - '0') ans = num.substr(i, 3);
                }
            } 
        }

        return ans;
    }
};
