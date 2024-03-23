class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* nextNode;

        while (head != NULL) {
            nextNode = head->next;
            head->next = newHead;
            newHead = head;
            head = nextNode;
        }

        return newHead;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        slow->next = NULL;
        
        ListNode* firstHalf = head;
        while (secondHalf != NULL) {
            ListNode* nextFirst = firstHalf->next;
            ListNode* nextSecond = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = nextFirst;

            firstHalf = nextFirst;
            secondHalf = nextSecond;
        }
    }
};
