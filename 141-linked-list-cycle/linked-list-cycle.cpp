/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // null ll sambhal lia
        if(head == NULL){
            return false;
        }
        //single element sambhal lia
        if(head->next == NULL){
            return false;
        }

     

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL){
            // ek step fast 
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                if(fast== slow){
                    return true;
                }
                slow = slow->next;
            }
        }
    return false;
    }
};