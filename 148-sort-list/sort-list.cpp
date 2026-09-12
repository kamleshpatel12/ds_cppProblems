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
    ListNode* sortList(ListNode* head) {
        vector<int>answer;
        ListNode*temp = head;
        while(temp!=nullptr){
            answer.push_back(temp->val);
            temp = temp->next;
        }
        sort(answer.begin(), answer.end());
        ListNode*dummy = new ListNode(0);
        ListNode*current  = dummy;
        temp = head;
        for(int i=0; i<answer.size(); i++){
            ListNode*var = new ListNode(answer[i]);
            current->next = var;
            current  =current->next;
        }
        return dummy->next;
    }
};