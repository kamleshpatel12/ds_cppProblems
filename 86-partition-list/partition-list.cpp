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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp = head;
        ListNode*dummy = new ListNode(0);
        ListNode*current = dummy;
        ListNode*dummy1 = new ListNode(0);
        ListNode*current1 = dummy1;
        while(temp != nullptr){
        
         ListNode* next = temp->next;
         temp->next = nullptr;
         if(temp->val < x) {
            current->next = temp;
            current = current->next;
         }

         else{
         current1->next = temp;
         current1 = current1->next;
         }

            temp = next;
        }
        current->next = dummy1->next;

        return dummy->next;
    }
};



