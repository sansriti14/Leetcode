class Solution {
private:
    int largestAreaRectangle(vector<int>& histogram) {
        int n = histogram.size();
        stack<int> st;
        int max_area = 0;
        
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || histogram[st.top()] >= histogram[i])) {
                int height = histogram[st.top()];
                st.pop();
                
                int width = (st.size() == 0) ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> histogram(cols);
        
        for(int i = 0; i < cols; i++) 
            histogram[i] = matrix[0][i] - '0';
        
        int max_area = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i == 0) continue;
                histogram[j] = (matrix[i][j] == '1') ? histogram[j] + 1 : 0;     
            }
            
            max_area = max(max_area, largestAreaRectangle(histogram));
        }
        
        return max_area;
    }
};