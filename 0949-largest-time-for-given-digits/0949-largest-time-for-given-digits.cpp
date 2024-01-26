class Solution {
public:
	string largestTimeFromDigits(vector<int>& arr) {
		string ans = "";
		sort(arr.begin(), arr.end());
        
		do {
			if((arr[0] == 2 && arr[1] <= 3 || arr[0] < 2) && arr[2] <= 5) {
				string temp = to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
				if(temp > ans) ans = temp;
			}  
            
		} while(next_permutation(arr.begin(), arr.end()));
        
		return ans;
	}
};