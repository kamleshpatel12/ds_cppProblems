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

        int count =0;
        ListNode*temp = head;
        while(temp!=nullptr){     
            count++;
            temp = temp->next;
        }

        int total = (count-n+1);
        temp = head;

       // deleting at beginning
        if(total == 1){
           head = head->next;
           return head;
        }
        for(int pos =1; pos<total-1 && temp!=nullptr; pos++){
           temp = temp->next;
        }

        if(temp==nullptr || temp->next==nullptr){
            // out of range
            return head;
        }
        temp->next = temp->next->next;
        return head;

    }
};

// to remove the nth node from the end , it would be total-n+1 th node from the beginning.
// to deelte something called x node, we need to traverse to pos-2 the element the node and delete it