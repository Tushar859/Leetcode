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
    ListNode* Rev(ListNode* head){
     // single and emoty node
     if(head == nullptr || head->next == nullptr){
         return head;
     }
    // ListNode* dummy = new Node(-1);
    // dummy->next = head;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr!=nullptr ){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
 
    }  
 return prev;
      
  }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* dummy = new ListNode(0);
     ListNode* temp = dummy;
     l1 = Rev(l1);
     l2 = Rev(l2);
     int carry =0;
     while(l1!=nullptr || l2!=nullptr || carry!=0){
        int sum =0;
        if(l1!=nullptr){
            sum+=l1->val;
            l1 = l1->next;
        } 
        if(l2!=nullptr){
            sum+=l2->val;
            l2 = l2->next;
        }
        sum+=carry;
        carry = sum/10;
        int digit=sum%10;
        ListNode* newNode = new ListNode(digit);
        temp->next = newNode;
        temp = temp->next;

     }
    ListNode* ans = Rev(dummy->next);
    return ans;
    
        
    }
};