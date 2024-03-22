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
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        ListNode *next;
        
        while(head!=NULL) {
            next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;
    }    
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow = slow->next;
        slow = reverseList(slow);
        
        while(slow!=NULL) {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};