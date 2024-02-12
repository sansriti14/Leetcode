class Solution {
private:
    void findFriends(int n, int id, int level, vector<int> adjList[], set<int>& myFriends) {
        queue<pair<int, int>> q;
        q.push({id, 0});
        
        vector<bool> visited (n, false);
        visited[id] = true;
        
        while(!q.empty()) {
            auto [person, curr_level] = q.front();
            q.pop();
            
            if(curr_level == level) myFriends.insert(person);
            if(curr_level > level) break;
            
            for(auto adjPerson: adjList[person]) {
                if(!visited[adjPerson]) {
                    visited[adjPerson] = true;
                    q.push({adjPerson, curr_level + 1});
                }
            }
        }
    }
    
public:
    struct comparator {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
        }
    };
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> adjList[n];
        for(int i = 0; i < n; i++) {
            adjList[i] = friends[i];
        }
        
        set<int> myFriends;
        findFriends(n, id, level, adjList, myFriends);
        
        unordered_map<string, int> mp;
        for(int person = 0; person < n; person++) {
            if(myFriends.find(person) != myFriends.end()) {
                for(auto watchedVideo: watchedVideos[person]) {
                    mp[watchedVideo]++;
                }
            }
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        for(auto [video, freq]: mp) {
            pq.push({freq, video});
        }
        
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};