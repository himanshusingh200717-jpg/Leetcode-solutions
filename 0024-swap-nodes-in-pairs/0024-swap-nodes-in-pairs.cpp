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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL){
            ListNode* first=curr;
            ListNode* second=curr->next;
            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;
            curr=first->next;

        }
        return dummy.next;
        
    }
};