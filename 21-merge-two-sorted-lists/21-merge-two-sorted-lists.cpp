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
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* curr = nullptr;
        if (list1->val < list2->val) {
            curr = list1;
            list1 = list1->next;
        } else {
            curr = list2;
            list2 = list2->next;
        }
        auto newList = new ListNode(curr->val);
        newList->next = mergeTwoLists(list1, list2);
        return newList;
    }
};