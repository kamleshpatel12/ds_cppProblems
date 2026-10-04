class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = 0;
            int val2 = 0;

            if(l1 != nullptr){
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            current->next = new ListNode(sum);
            current = current->next;
        }

        return dummy->next;
    }
};