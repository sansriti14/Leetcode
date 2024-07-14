class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        
        stack<pair<string, int>> elementsStack;
        stack<int> multiplierStack;
        
        int currentMultiplier = 1, value = 1;

        for (int i = n - 1; i >= 0; i--) {
            char currentChar = formula[i];
            
            if (currentChar >= 'a' && currentChar <= 'z') {
                string element = "";
                while (!(formula[i] >= 'A' && formula[i] <= 'Z')) {
                    element = formula[i] + element;
                    i--;
                }
                
                element = formula[i] + element;
                int frequency = currentMultiplier * value;
                elementsStack.push({element, frequency});
                value = 1;
            } 
            
            else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                string element = "";
                element += formula[i];
                int frequency = currentMultiplier * value;
                elementsStack.push({element, frequency});
                value = 1;
            } 
            
            else if (currentChar == ')') {
                multiplierStack.push(value);
                currentMultiplier *= value;
                value = 1;
            } 
            
            else if (currentChar == '(') {
                currentMultiplier /= multiplierStack.top();
                multiplierStack.pop();
            } 
            
            else {
                string number = "";
                while (formula[i] <= '9' && formula[i] >= '0') {
                    number = formula[i] + number;
                    i--;
                }
                
                i++; 
                value = stoi(number);
            }
        }
        
        map<string, int> elementCountMap;
        while (!elementsStack.empty()) {
            auto elementPair = elementsStack.top(); 
            elementsStack.pop();
            string element = elementPair.first;
            int frequency = elementPair.second;
            elementCountMap[element] += frequency;
        }
        
        string ans = "";
        for (const auto& elementPair : elementCountMap) {
            string element = elementPair.first;
            string frequency = "";
            if (elementPair.second != 1) {
                frequency += to_string(elementPair.second);
            }
            
            ans += element + frequency;
        }
        
        return ans;
    }
};
