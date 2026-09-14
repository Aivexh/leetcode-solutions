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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node helps when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node that needs to be reversed
        ListNode* curr = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++) {

            ListNode* next = curr->next;

            curr->next = next->next;

            next->next = prev->next;

            prev->next = next;
        }

        return dummy->next;
    }
};