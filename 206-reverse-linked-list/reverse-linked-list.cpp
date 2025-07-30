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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL){
            return 0;
        }
        stack< ListNode*> rev;
        while(temp!=NULL){
            rev.push(temp);
            temp=temp->next;
        }
         ListNode* newhead=rev.top();
            rev.pop();
            temp= newhead;


        while(!rev.empty()){
            temp->next=rev.top();
            rev.pop();
            temp=temp->next;

        }
        temp->next=NULL;
        return newhead;
    }
};