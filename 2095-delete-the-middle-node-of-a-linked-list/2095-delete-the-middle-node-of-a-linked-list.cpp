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
        int idxCnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            idxCnt++;
            temp = temp->next;
        }

        int mid = (idxCnt + 1) / 2;
        if(idxCnt==1)return NULL;
        if(idxCnt%2)mid--;
        temp = head;
        while (temp != NULL) {

            if (mid == 1) {
                break;
            }
            mid--;
            temp = temp->next;
        }
  
        temp->next = temp->next->next;
        return head;
    }
};