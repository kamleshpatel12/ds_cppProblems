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
    bool isPalindrome(ListNode* head) {
         ListNode *slow = head;
         ListNode *fast = head;
         
         while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast  = fast->next->next;
         }

         ListNode* prev = nullptr;
         ListNode* next = nullptr;
         while(slow!=nullptr){
            next  = slow->next;
            slow->next  = prev;
            prev = slow;
            slow = next;
         }
        
       while(prev!=nullptr){
        if(prev->val!=head->val){
            return false;
        }
        prev = prev->next;
        head  = head->next;
       }
       return true;
    }
};