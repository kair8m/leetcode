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
    ListNode* deleteDuplicates(ListNode* head) {
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            if (!next)
                break;
            if (curr->val == next->val) {
                curr->next = next->next;
                delete next;
            } else
                curr = next;
        }
        return head;
    }
};