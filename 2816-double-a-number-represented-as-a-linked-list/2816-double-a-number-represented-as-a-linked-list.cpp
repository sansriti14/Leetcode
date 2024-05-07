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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL; 
        ListNode* nextNode;
        
        while(head != NULL) {
            nextNode = head->next;
            head->next = newHead;
            
            newHead = head;
            head = nextNode;
        }
        
        return newHead;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* reverse_head = reverseList(head);
        
        int carry = 0;
        ListNode* temp = reverse_head;
        while (temp != NULL) {
            int double_value = 2 * temp->val + carry;
            temp->val = double_value % 10;
            carry = double_value / 10;
            temp = temp->next;
        }
        
        ListNode* newHead = reverseList(reverse_head);
        if (carry) {
            ListNode* node = new ListNode(carry);
            node->next = newHead;
            return node;
        }
        
        return newHead;
    }
};