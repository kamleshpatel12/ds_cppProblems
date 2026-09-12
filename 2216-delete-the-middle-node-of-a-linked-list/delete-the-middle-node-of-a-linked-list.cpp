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
    ListNode* deleteMiddle(ListNode* head) {
        int count =0;
        ListNode*temp =head;
        if(head->next == nullptr)
            return nullptr;
        while(temp!=nullptr){
            temp = temp ->next;
            count++;
        }
        int pos = (count/2)+1;
        temp =head;
        for(int i=1; i<pos-1; i++){
         temp = temp->next;
        }
       
        temp->next = temp->next->next;
        return head;
    }
};

// even and odd
// odd  - n/2+1the node
// even - n/2+1

// that means i need to traverse till the n/2th node 