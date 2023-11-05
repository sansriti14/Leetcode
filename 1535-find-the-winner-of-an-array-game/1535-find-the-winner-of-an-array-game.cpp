class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
		int maxNumSeen = arr[0];           
        int maxCount = 0;
        for(int i = 1; i < arr.size(); i++) {
            if (maxNumSeen > arr[i]) {               
                maxCount++;                   
            }
            
            else {
                maxNumSeen = arr[i];         
                maxCount = 1;                
            }
            
            if (maxCount == k) 
                return maxNumSeen;
        }
        
        return maxNumSeen;
    }
};