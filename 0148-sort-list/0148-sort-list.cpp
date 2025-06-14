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

ListNode* mergeList(ListNode* h1,ListNode* h2){
    if(h1==NULL || h2==NULL){
        return h1==NULL?h2:h1;
    }

    if(h1->val<=h2->val){
        h1->next=mergeList( h1->next,h2 );
        return h1;
    }else{
        h2->next=mergeList(h1,h2->next);
        return h2;
    }

}

ListNode* findMiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast->next!=NULL && fast!=NULL  ){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid=findMiddle(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        return mergeList(left,right);

    }
};