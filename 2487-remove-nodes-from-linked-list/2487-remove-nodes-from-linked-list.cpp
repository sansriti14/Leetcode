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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;

        while (temp != NULL) {
            if (st.empty()) st.push(temp);
            
            else {
                while (temp->val > st.top()->val) {
                    st.pop();
                    if(st.empty()) break;
                }
                
                st.push(temp);
            }
            
            temp = temp->next;
        }

        ListNode* prev_node = NULL;
        
        while(!st.empty()){
            ListNode* curr_node = st.top();
            st.pop();
            
            curr_node->next = prev_node;
            prev_node = curr_node;
        
        }

        return prev_node;
    }
};