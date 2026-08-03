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
    int len(ListNode* head, int n){
        int count =0;
      ListNode* temp = head;
      while(temp!=nullptr){
        count++;
        temp=temp->next;
      }
      return count-n+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      int pos = len(head,n);

      if(pos==1){
        // phela node delete kr rhe
       ListNode* temp = head;
       head = head->next;
       delete temp;
       dummy->next=head;
       return dummy->next;

      } 
      
    ListNode* prev = dummy;
     ListNode* curr = head;
     while(pos>1){
        prev = curr;
        curr = curr->next;
        pos--;
     }
      prev->next = curr->next;
      curr->next = nullptr;
      delete curr;
     return dummy->next;
     
        
    }
};