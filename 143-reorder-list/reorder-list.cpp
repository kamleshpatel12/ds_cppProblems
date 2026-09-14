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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;

        // 1. Find length
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // 2. Split
        temp = head;
        int pos = (count / 2) + 1;

        for(int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        ListNode* second = temp->next;
        temp->next = nullptr;

        // 3. Reverse second half
        ListNode* prev = nullptr;

        while(second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // 4. Merge
        ListNode* first = head;
        second = prev;

        while(second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};