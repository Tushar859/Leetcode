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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   
        }
    };

    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* temp = head;

        while (temp != nullptr) {
            pq.push(temp);
            temp = temp->next;
        }

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            curr->next = nullptr;
        }

        return ans->next;
    }
};
