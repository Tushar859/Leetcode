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
      // single element;
      if(head == nullptr){
        return false;
      }
      if(head->next == nullptr){
        return false;
      }
      
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow= slow->next;
        if(slow == fast){
            return true;
            break;
        }
      }
    return false;
    


    }
};