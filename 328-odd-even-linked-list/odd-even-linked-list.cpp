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
    ListNode* oddEvenList(ListNode* head) {
        // empty and sigle ele handle kr dia
      if(head==nullptr || head->next ==nullptr){
        return head;
      }
      vector<int>ans;
       ListNode* temp = head;
       while(temp!=nullptr){
         ans.push_back(temp->val);
         temp=temp->next;
       }
       ListNode* newNode = new ListNode(-1);
         ListNode* head1 = newNode;
          ListNode* tail = newNode;
        for(int i=0;i<ans.size();i=i+2){
            ListNode* temp = new ListNode(ans[i]);
            tail->next = temp;
            tail = tail->next;
        }
         for(int i=1;i<ans.size();i=i+2){
            ListNode* temp = new ListNode(ans[i]);
            tail->next = temp;
            tail = tail->next;
        }
     return newNode->next;
      
        
    }
};