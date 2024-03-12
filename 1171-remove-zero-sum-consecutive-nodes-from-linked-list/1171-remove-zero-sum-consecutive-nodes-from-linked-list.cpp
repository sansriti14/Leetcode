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
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        
        unordered_map<int, ListNode*> mp;
        mp[0] = newHead;
        
        while(head != NULL) {
            prefixSum += head->val;
            
            if(mp.find(prefixSum) != mp.end()) {
                ListNode *start = mp[prefixSum];
                ListNode *temp = start;
                
                int preSum = prefixSum;
                while(temp != head){
                    temp = temp->next;
                    preSum += temp->val;
                    if(temp != head)
                        mp.erase(preSum);
                }
                
                start->next = head->next;
            }
            
            else {
                mp[prefixSum] = head;
            }
            
            head = head->next;
        }
        
        return newHead->next;
    }
};