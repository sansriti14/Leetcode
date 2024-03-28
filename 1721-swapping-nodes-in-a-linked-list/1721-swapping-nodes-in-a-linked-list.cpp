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
        
        int n = 0;
        ListNode* ptr = head;
        while (ptr != NULL) {
            n++;
            ptr = ptr->next;
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        for (int i = 1; i <= k - 1; i++) ptr1 = ptr1->next;
        for (int i = 1; i <= n - k; i++) ptr2 = ptr2->next;
        
        swap(ptr1->val, ptr2->val);
        
        return head;
    }
};