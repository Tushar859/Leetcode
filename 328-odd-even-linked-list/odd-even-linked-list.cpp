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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        ListNode* temp = even->next;   

        while (temp != nullptr) {
            odd->next = temp;          
            odd = temp;

            if (temp->next == nullptr){
                break;
            }

            even->next = temp->next;  
            even = temp->next;

            temp = temp->next->next;   
        }
         even->next = nullptr;
        odd->next = evenHead;
        return head;
    }
};
