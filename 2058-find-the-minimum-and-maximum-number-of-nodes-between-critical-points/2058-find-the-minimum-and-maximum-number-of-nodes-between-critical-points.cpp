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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* curr=head->next;
    ListNode* prev=head;
    int i=1;
    int firstcritpos=0;
    int prevcritpos=0;
    int mindist=INT_MAX;
    while(curr->next!=NULL){
    if((curr->val>curr->next->val&&curr->val>prev->val)||(curr->val<curr->next->val&&curr->val<prev->val)){
        if(prevcritpos==0){
            firstcritpos=i;
            prevcritpos=i;
        }else{
            mindist=min(mindist,i-prevcritpos);
            prevcritpos=i;
        }
      

    }
      i++;
        prev=curr;
        curr=curr->next;

    }
        if(mindist==INT_MAX)return {-1,-1};
    return {mindist,prevcritpos-firstcritpos};
        
    }
};