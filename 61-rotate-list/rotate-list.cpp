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

    ListNode* findNode(ListNode* head, int pos)
    {
        while(pos > 1)
        {
            head = head->next;
            pos--;
        }

        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
            
        int len = 1;
        ListNode* tail = head;

        while(tail->next != nullptr)
        {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if(k == 0)
            return head;
        // Make circular linked list
        tail->next = head;
        // Find new last node
        ListNode* newLastNode = findNode(head, len - k);
        // New head
        head = newLastNode->next;
        // Break the link
        newLastNode->next = nullptr;

        return head;
    }
};