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
  
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
      unordered_map<ListNode* , bool>vis;
       ListNode* temp = headA;
       while(temp!=nullptr){
         vis[temp]=true;
         temp=temp->next;
       }
        ListNode* temp2 = headB;
        while(temp2!=nullptr){
          
            if(vis.find(temp2) != vis.end())
            {
                return temp2;
            }
          else{
            temp2= temp2->next;
          }
        }
     return NULL;
    }
};