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
        ListNode* newHead = nullptr; 
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* head = new ListNode(0); 
        ListNode* current = head;
        
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            sum = sum % 10;
            current->next = new ListNode(sum);
            current = current->next;
        }
        
        ListNode* result = reverseList(head->next);
        delete head; 
        return result;
    }
};
