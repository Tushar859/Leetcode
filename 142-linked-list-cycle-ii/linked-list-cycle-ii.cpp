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
    ListNode *detectCycle(ListNode *head) {
        // if(head == nullptr){
        //     return nullptr;
        // }
        // if(head->next == nullptr){
        //     return  nullptr;
        // }
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast!=nullptr && fast->next!=nullptr){
         slow = slow->next;
         fast = fast->next->next;
         if(slow == fast){
            break ;
         }
        
       }
       // check whether cycke was ir nit
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
                }
       // yha aaye mtlb slow fast mil chuke
       slow = head;
       // slow fast ek step move krege
       while(fast!=slow){
        slow = slow->next;
        fast = fast->next;
       }
       return slow;
        
    }
};