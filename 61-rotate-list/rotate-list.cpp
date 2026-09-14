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
        ListNode*current  = head;
        if(head == nullptr)
        return head;
        int count =0;
        while(current!=nullptr){
            current  = current->next;
            count++;
        }

        int rotation = k%count;
        current  = head;
      
        if(k==0 || rotation==0)
        return head;



        for(int i=0; i<rotation; i++){
            ListNode*temp = current;

            //second last element
            while(temp->next->next!=nullptr){
                temp = temp->next;
            }
            ListNode* last = temp->next; // this one points to  5
            temp->next = nullptr;    // now 4->x
            last ->next = current;   // 5->1...->4->x
         
            current  = last;
        }
        return current;
    }
};