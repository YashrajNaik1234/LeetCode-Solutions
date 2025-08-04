class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        
        int st(0),maxLen(0);
        for(int end(0);end < fruits.size();end++){
            mp[fruits[end]]++;

            while(mp.size() > 2){
                mp[fruits[st]]--;
                if(mp[fruits[st]] == 0) mp.erase(fruits[st]);
                st++;
            }

            maxLen = max(maxLen, end - st + 1);
        }

        return maxLen;
    }
};
