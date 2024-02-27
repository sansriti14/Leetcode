class Solution { 
private:
    bool check(vector<int>& arr, int index, vector<bool>& visited) {
        if(index < 0 || index >= arr.size() || visited[index] == true) return false;
        if(arr[index] == 0) return true;;
        
        visited[index] = true;
        
        return check(arr, index - arr[index], visited) || check(arr, index + arr[index], visited);
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited (arr.size(), false);
        
        return check(arr, start, visited);
    }
};