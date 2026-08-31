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
        ListNode* temp=head->next;
        ListNode* prev=head;
        int idx=2, first=-1, last=-1;
        int mini=INT_MAX;
        vector<int> nodes;
        while(temp->next!=NULL){
            ListNode* right=temp->next;
            if((prev->val>temp->val && right->val>temp->val) || (prev->val<temp->val && right->val<temp->val)){
                if(first==-1) first=idx;
                else mini=min(mini, idx-last);
                last=idx;
            }
            prev=temp;
            temp=right;
            idx++;
        }
        if(first==-1 || first==last) return {-1,-1};
        return {mini, last-first};
    }
};