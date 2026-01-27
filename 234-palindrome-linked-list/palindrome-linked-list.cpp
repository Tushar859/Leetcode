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
    bool isPalindrome(ListNode* head) {
       int count=0;
       if(head->next==nullptr){
        return 1;
       }
       ListNode*temp=head;
       while(temp){
        count++;
        temp=temp->next;
       }
       count/=2;
       ListNode*curr=head;
       ListNode*prev=nullptr;
       while(count--){
        prev=curr;
        curr=curr->next;
       }
       prev->next=nullptr;
       ListNode*front;
       prev=nullptr;
       while(curr){
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
       }
       ListNode*head1=head;
        ListNode*head2=prev;
        while(head1){
            if(head1->val!= head2->val){
                return 0;
            }
            head1=head1->next;
            head2=head2->next;
        }

        return 1;

    }
};