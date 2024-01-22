class Solution {
private:
    void findIndices(string& s, string& a, string& b, vector<int>& a_indices, vector<int>& b_indices) {
        int n = s.length();
        int a_size = a.size();
        int b_size = b.size();
        
        int i = 0, j = 0;
        while(i < n || j < n) {
            while(i < n && s[i] != a[0]) i++;
            while(j < n && s[j] != b[0]) j++;
            if(i < n && s.substr(i, a_size) == a) a_indices.push_back(i);
            if(j < n && s.substr(j, b_size) == b) b_indices.push_back(j);
            i++;
            j++;
        }
    }
    
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> a_indices, b_indices;
        findIndices(s, a, b, a_indices, b_indices);
        
        int n = a_indices.size();
        int m = b_indices.size();
        
        vector<int> beautiful_indices;
        for(auto& i : a_indices) {
            auto it = lower_bound(b_indices.begin(), b_indices.end(), i - k);
            if((it != b_indices.end()) && (abs(*it - i) <= k)) beautiful_indices.push_back(i);
        }

        return beautiful_indices;
    }
};