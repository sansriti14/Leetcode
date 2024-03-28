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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* currNode = head;
        head = head->next;
        ListNode* prevNode = NULL;
        ListNode* nextNode;
        
        while (currNode != NULL && currNode->next != NULL) {
            if(prevNode != NULL) prevNode->next = currNode->next;
            
            nextNode = currNode->next->next;
            currNode->next->next = currNode;
            
            currNode->next = nextNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return head;
    }
};