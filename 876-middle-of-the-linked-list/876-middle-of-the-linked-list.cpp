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
        unordered_map<int, ListNode*> nodes;
        auto curr = head;
        int len = 0;
        while (curr) {
            nodes[len++] = curr;
            curr = curr->next;
        }
        int middle = len / 2;
        return nodes[middle];
    }
};