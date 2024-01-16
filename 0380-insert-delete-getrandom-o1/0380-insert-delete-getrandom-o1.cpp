class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;
    
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            int last_val = arr.back();
            mp[last_val] = mp[val];
            arr[mp[val]] = last_val;
            arr.pop_back();
            mp.erase(val);
            
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */