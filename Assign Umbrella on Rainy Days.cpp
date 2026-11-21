class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int a(0),b(0), n(rain.size());

        vector<string> ans(n, "None");
        for(int i(0);i < n;i++){
            bool ak = (i < n - 1 and rain[i] == 1 and rain[i + 1] == 1);
            bool bk = (rain[i] == 1);

            if(ak and bk){
                if(a <= b) ans[i] = "Alice", a++;
                else ans[i] = "Bob", b++;
            }
            else if(ak) ans[i] = "Alice", a++;
            else if(bk) ans[i] = "Bob", b++;
        }

        return ans;
    }
};
