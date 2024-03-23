class Solution {
public:
    void reorderList(ListNode* head) {
       if (head->next == NULL || head->next->next == NULL) return; 
        
        stack<ListNode*> st;
        ListNode* temp = head;
        int size = 0;
        while (temp != NULL) {
            size++;
            st.push(temp);
            temp = temp->next;
        }
        
        temp = head;
        
        size = size / 2;
        while (size--) {
            ListNode *element = st.top();
            st.pop();
            
            element->next = temp->next;
            temp->next = element;
            temp = temp->next->next;
        }
        
        temp->next = NULL;
    }
};