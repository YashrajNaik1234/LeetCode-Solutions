class TaskManager {
public:
    map<int, pair<int,int>> mp;
    set<pair<int,int>> st;
    
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i: tasks){
            st.insert({i[2], i[1]}); mp[i[1]] = {i[0], i[2]};
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        pair<int,int> p = mp[taskId];
        st.erase({p.second, taskId});
        st.insert({newPriority, taskId});
        mp[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        st.erase({mp[taskId].second, taskId}); mp.erase(taskId);
    }
    
    int execTop() {
        if(mp.empty()) return -1;

        auto it = --st.end();
        pair<int,int> p = *it;
        int ans = mp[p.second].first;
        mp.erase(p.second); st.erase(it);
        return ans;
    }
};
