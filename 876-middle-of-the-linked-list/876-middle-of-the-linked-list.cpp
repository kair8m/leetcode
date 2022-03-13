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
    ListNode* middleNode(ListNode* head) {
        auto curr = head;
        int len = 0;
        while (curr) {
            curr = curr->next;
            len++;
        }
        int middle = len / 2;
        curr = head;
        while (middle-- > 0) 
            curr = curr->next;
        return curr;
    }
};