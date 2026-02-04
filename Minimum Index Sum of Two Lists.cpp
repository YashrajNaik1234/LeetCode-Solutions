class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans{""}; int sum(INT_MAX);
        map<string,pair<int, int>> mp;

        for(int i(0);i < list1.size();i++){
            if(mp.find(list1[i]) != mp.end()) continue;
            mp[list1[i]] = {i, 1};
        }

        for(int i(0);i < list2.size();i++){
            if(mp.find(list2[i]) != mp.end() and mp[list2[i]].second == 1){
                mp[list2[i]] = {mp[list2[i]].first + i, 2};
            }
            else continue;
        }

        for(auto i:mp){
            if(i.second.second == 2){
                if(i.second.first < sum){
                    sum = i.second.first;
                    ans.front() = i.first;
                }
            }
        }

        for(auto i:mp){
            if(i.second.first == sum and i.second.second == 2){
                if(ans.front() == i.first) continue;
                else ans.push_back(i.first);
            }
        }

        return ans;
    }
};
