class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2) return 0;
        
        int n1 = version1.length();
        int n2 = version2.length();
        
        int i = 0, j = 0;
        
        while (i < n1 || j < n2) {
            string temp1 = "", temp2 = "";
            
            while (i < n1 && version1[i] != '.') temp1 += version1[i++];
            while (j < n2 && version2[j] != '.') temp2 += version2[j++];
            
            int val1 = temp1.empty() ? 0 : stoi(temp1);
            int val2 = temp2.empty() ? 0 : stoi(temp2);
            
            if (val1 < val2) return -1; 
            if (val1 > val2) return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};