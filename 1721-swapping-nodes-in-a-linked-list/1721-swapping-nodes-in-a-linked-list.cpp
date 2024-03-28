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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL) return head;
        
        ListNode* ptr1 = head;
        for (int i = 1; i < k; i++) ptr1 = ptr1->next;
        
        ListNode* slow = head;
        ListNode* fast = ptr1->next;
        
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        swap(slow->val, ptr1->val);
        
        return head;
    }
};