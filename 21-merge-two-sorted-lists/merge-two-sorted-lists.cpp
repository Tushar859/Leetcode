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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 ==nullptr && list2 == nullptr){
            return nullptr;
        }
        // single element
        if(list1 != nullptr && list2 ==nullptr){
            return list1;
        }
         if(list2!= nullptr && list1 ==nullptr){
            return list2;
        }
         ListNode* curr = new ListNode();

       ListNode* temp1 = list1;
       ListNode* temp2 =  list2;
       ListNode* cur = curr;

       while(temp1!=NULL && temp2!=NULL ){
        if(temp1->val <= temp2->val){
            // daal do
            //cur ->val = temp1->val;
         // iss trh dalte hain new element   
        cur->next = new ListNode(temp1->val);
            cur = cur->next;
            temp1 =temp1->next;

        }
        else{
           //temp1->val <= temp2->val
          // cur ->val = temp2->val;
          
        cur->next = new ListNode(temp2->val);
            cur = cur->next;
           temp2 = temp2->next;

        }
    
       }
   while(temp1!=NULL){
         cur->next = new ListNode(temp1->val);
          cur = cur->next;
         temp1 = temp1->next;
           }
 while(temp2!=NULL){
         cur->next = new ListNode(temp2->val);
          cur = cur->next;
         temp2 = temp2->next;
              }

 return curr->next;

        
    }
};