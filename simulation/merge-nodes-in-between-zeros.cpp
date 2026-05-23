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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node=head->next;
        ListNode* nxt=node;
        while(nxt!=NULL){
            int sum=0;
            while(nxt->val!=0){
                sum+=nxt->val;
                nxt=nxt->next;
            }
            node->val=sum;
            nxt=nxt->next;
            node->next=nxt;
            node=node->next;
        }
        return head->next;
    }
};