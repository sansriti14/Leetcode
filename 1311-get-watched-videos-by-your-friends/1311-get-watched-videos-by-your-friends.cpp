using pis = pair<int, string>;

class Solution {
private:
    void findFriends(int id, int level, vector<vector<int>>& friends, vector<int>& myFriends) {
        int n = friends.size();        
        
        queue<pair<int, int>> q;
        q.push({id, 0});
        
        vector<bool> visited (n, false);
        visited[id] = true;
        
        while(!q.empty()) {
            auto [person, curr_level] = q.front();
            q.pop();
            
            if(curr_level == level) myFriends.push_back(person);
            if(curr_level > level) break;
            
            for(auto adjPerson: friends[person]) {
                if(!visited[adjPerson]) {
                    visited[adjPerson] = true;
                    q.push({adjPerson, curr_level + 1});
                }
            }
        }
    }
    
public:
    struct comparator {
        bool operator()(const pis& a, const pis& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
        }
    };
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> myFriends;
        findFriends(id, level, friends, myFriends);
        
        unordered_map<string, int> mp;
        for(auto myFriend: myFriends) {
            for(auto watchedVideo: watchedVideos[myFriend]) {
                mp[watchedVideo]++;
            }
        }
        
        priority_queue<pis, vector<pis>, comparator> pq;
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