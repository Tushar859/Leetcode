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
    ListNode* reverse(ListNode* prev, ListNode* curr) {
        if (curr == nullptr) return prev;
        ListNode* front = curr->next;
        curr->next = prev;
        return reverse(curr, front);
    }

    ListNode* doubleIt(ListNode* head) {

     
        head = reverse(nullptr, head);

        int carry = 0;
        ListNode* temp = head;

   
        while (temp != nullptr) {
            int number = temp->val * 2 + carry;
            temp->val = number % 10;
            carry = number / 10;

            if (temp->next == nullptr) break;
            temp = temp->next;
        }

 
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }


        head = reverse(nullptr, head);
        return head;
    }
};
