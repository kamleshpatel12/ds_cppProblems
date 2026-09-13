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
    void reorderList(ListNode* head) {
        ListNode*temp  = head;
        int count =0;
        while(temp!=nullptr){
            count++;
            temp= temp->next;
        }
        temp = head;
        int pos = (count/2)+1;

        for(int i=1; i<=pos-1; i++){
         temp = temp->next;
        }
        ListNode*current   = temp->next;
        temp->next =nullptr;
        
        
        ListNode*prev = nullptr;
        ListNode*next  = nullptr;
        while(current!=nullptr){
            next  = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        ListNode* first = head;
        ListNode* second = prev;

        while(first != nullptr && second != nullptr){
  
        ListNode* nextFirst = first->next;
        ListNode* nextSecond = second->next;

         first->next = second;
         second->next = nextFirst;

         first = nextFirst;
         second = nextSecond;
        }
    }
};