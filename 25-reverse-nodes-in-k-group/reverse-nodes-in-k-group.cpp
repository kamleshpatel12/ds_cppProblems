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
    ListNode*reversing(ListNode*head){
        ListNode*current  = head;
        ListNode*prev = nullptr;
        ListNode*next  = nullptr;

        while(current!=nullptr){
            next = current->next;
            current->next  = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1)
            return head;

        ListNode* current = head;
        ListNode* newHead = nullptr;
        ListNode* prevTail = nullptr;

        while (current != nullptr) {
            ListNode* temp = current;

            // Find the kth node of this group
            for (int i = 1; i < k; i++) {
                if (temp == nullptr)
                    break;
                temp = temp->next;
            }

            // Fewer than k nodes remain: leave them unchanged
            if (temp == nullptr)
                break;

            // Save the next group
            ListNode* remaining = temp->next;

            // Disconnect the current group
            temp->next = nullptr;

            // Reverse the current group
            ListNode* revList = reversing(current);

            // Set the head of the final list
            if (newHead == nullptr)
                newHead = revList;

            // Connect the previous group to this reversed group
            if (prevTail != nullptr)
                prevTail->next = revList;

            // The original group head is now its tail
            prevTail = current;

            // Move to the next group
            current = remaining;
        }

        // Connect any remaining nodes that weren't reversed
        if (prevTail != nullptr)
            prevTail->next = current;

        return (newHead != nullptr) ? newHead : head;
    }
};