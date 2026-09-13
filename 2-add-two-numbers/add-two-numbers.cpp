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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1  = l1;
        ListNode*temp2 = l2;

      ListNode*dummy = new ListNode(0);
      ListNode*current  = dummy;
      int carry =0;
      int sum =0;
      while(temp1!=nullptr && temp2!=nullptr){
        sum = carry + temp1->val+temp2->val;
        carry = sum / 10;
        sum = sum % 10;
        ListNode*var = new ListNode(sum);
        current ->next = var;
        current = current->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
      }

    while(temp1 != nullptr || temp2 != nullptr || carry != 0) {

    int val1 = 0;
    int val2 = 0;

    if(temp1 != nullptr) {
        val1 = temp1->val;
        temp1 = temp1->next;
    }

    if(temp2 != nullptr) {
        val2 = temp2->val;
        temp2 = temp2->next;
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


