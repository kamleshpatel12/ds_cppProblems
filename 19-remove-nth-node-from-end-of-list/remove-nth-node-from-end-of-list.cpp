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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1)
        return nullptr;

      ListNode*slow = head;
      ListNode*fast = head;
      
        // Keep fast n nodes ahead of slow
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }

           // If fast becomes nullptr, n == length
        if(fast==nullptr){
            return head->next;
        }

       

      while(fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
      }

      slow->next = slow->next->next;
      return head;

     

    }
};




