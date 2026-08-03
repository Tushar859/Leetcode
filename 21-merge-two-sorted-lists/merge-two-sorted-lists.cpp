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
        vector<int> v;
        ListNode* temp = list1;
        while(temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while(temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        for(int i = 0; i < v.size(); i++) {
            ListNode* newNode = new ListNode(v[i]);
            tail->next = newNode;
            tail = newNode;
        }

        return dummy->next;
    }
};
