class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        // Deep copy of the list
        ListNode* copyHead = new ListNode(head->val);
        ListNode* p1 = head->next;
        ListNode* p2 = copyHead;

        while (p1 != nullptr) {
            p2->next = new ListNode(p1->val);
            p2 = p2->next;
            p1 = p1->next;
        }

        // Reverse the copied list
        ListNode* head2 = reverseList(copyHead);

        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val != temp2->val)
                return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};