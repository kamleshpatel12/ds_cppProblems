class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Handle duplicates at the beginning
        while (head != nullptr && head->next != nullptr &&
               head->val == head->next->val) {

            int duplicateVal = head->val;

            while (head != nullptr && head->val == duplicateVal) {
                head = head->next;
            }

            if (head == nullptr) {
                return nullptr;
            }
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prevslow = nullptr;

        while (fast != nullptr) {
            if (slow->val != fast->val) {
                // No duplicate group at slow
                prevslow = slow;
                slow = fast;
                fast = fast->next;
            }
            else {
                // Duplicate group found
                int duplicateVal = slow->val;

                while (fast != nullptr && fast->val == duplicateVal) {
                    fast = fast->next;
                }

                // Remove the duplicate group
                prevslow->next = fast;

                // Move slow to the next remaining node
                slow = fast;

                if (slow != nullptr) {
                    fast = slow->next;
                }
            }
        }

        return head;
    }
};