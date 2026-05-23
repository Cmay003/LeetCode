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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head->next;
        ListNode* eventemp=head;
        ListNode* oddtemp=head->next;
        while(oddtemp!=NULL && oddtemp->next!=NULL){
            eventemp->next = eventemp->next->next;
            oddtemp->next = oddtemp->next->next;

            oddtemp=oddtemp->next;
            eventemp=eventemp->next;
        }
        eventemp->next=odd;
        return head;
    }
};