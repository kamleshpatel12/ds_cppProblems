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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr)
        return head;

        int count =1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            count++;
        }

        int rotation = k%count;

      
        if(k==0 || rotation==0)
        return head;

       ListNode*newTail = head;
       for(int i=0; i<count-rotation-1; i++){
          newTail = newTail->next;
       }

       tail->next  = head;
       ListNode*newHead = newTail->next;
       newTail->next = nullptr;
       return newHead;

    }
};





