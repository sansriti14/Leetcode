/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {       
private:
    bool isLocalMinima(ListNode* prev, ListNode* curr) {
        return (prev->val > curr->val && curr->val < curr->next->val);
    }
    
    bool isLocalMaxima(ListNode* prev, ListNode* curr) {
        return (prev->val < curr->val && curr->val > curr->next->val);
    }
    
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next == NULL || head->next->next == NULL) return {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        vector<int> positions;
        int position = 1;
        
        while (curr->next != NULL) {
            if (isLocalMinima(prev, curr) || isLocalMaxima(prev, curr)) {
                positions.push_back(position);
            }
            
            prev = curr;
            curr = curr->next;
            position++;
        }
        
        if (positions.size() < 2) return {-1, -1};
        
        int minDistance = INT_MAX;
        int maxDistance = positions.back() - positions[0];
        
        for (int i = 0; i < positions.size() - 1; i++) {
            minDistance = min(minDistance, positions[i + 1] - positions[i]);
        }
        
        return {minDistance, maxDistance};
    }
};