/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int>mp;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;

        int size1=0;
        while(temp1!=nullptr){
         size1++;
         temp1 = temp1->next;
        }
  
        int size2=0;  
        while(temp2!=nullptr){
         size2++;
         temp2 = temp2->next;
        }

        temp1= headA;
        temp2= headB;

        int diff = abs(size1-size2);
        
        if(size1>size2){
        for(int i=1; i<=diff; i++){
           temp1=temp1->next;
         }
        }
        else{
            for(int i=1; i<=diff; i++){
                temp2 =temp2->next;
            }
        }


        while(temp1!=nullptr){
            if(temp1==temp2){
               return temp2;
            }
           temp1= temp1->next;
           temp2=temp2->next;
        }
        return nullptr;
    }
};