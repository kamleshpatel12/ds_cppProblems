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
        ListNode*current = l1;
        ListNode*prev = nullptr;
        ListNode*next  = nullptr;
        while(current!=nullptr){
            next = current->next;
            current->next  = prev;
            prev = current;
            current  = next;
        }
        ListNode*List1= prev;
        ListNode*first = List1;

        current = l2;
        prev = nullptr;
        next = nullptr;

        while(current!=nullptr){
            next = current->next;
            current->next  = prev;
            prev = current;
            current  = next;
        }

        ListNode*List2= prev;
        ListNode*second = List2;

        int carry = 0;

        ListNode* dummy = new ListNode(0);
        current = dummy;

        while(first!=nullptr || second != nullptr || carry!=0){
            int val1=0;
            int val2=0;
            if(first!=nullptr){
             val1 =first->val;
             first  = first->next;
            }

            if(second!=nullptr){
                val2 = second->val;
                second  = second->next;
            }
            int sum  = val1+val2+carry;
            carry = sum/10;
            sum = sum%10;
            
            current->next = new ListNode(sum);
            current  = current->next;
        }
        current = dummy->next;
      prev = nullptr;

      while(current != nullptr) {
       next = current->next;
      current->next = prev;
      prev = current;
        current = next;
     }

      return prev;


    }
};

 