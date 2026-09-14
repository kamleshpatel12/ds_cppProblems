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
        ListNode*first = head;
        ListNode*temp = head;
        
        for(int i=1; i<=left-1; i++){
            temp = first;
            first = first->next;
        }

        ListNode*last = head;
       
       for(int i=1; i<=right; i++){
          last  = last->next;
       }

       ListNode*current  = first;
       ListNode*prev = nullptr;
       ListNode*next = nullptr;
       while(current!=last){
         next  = current->next;
         current->next  = prev;
         prev = current;
         current = next;
       }
       
       if(left>1){
        temp->next  = prev;
       first->next = last;
       }
       else{
      head = prev;
      first->next = last;
     }


       return head;

    }
};



