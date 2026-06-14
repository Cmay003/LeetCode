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
    //BRUTE SOLUTION
    // int pairSum(ListNode* head) {
    //     ListNode* temp=head;
    //     vector<int> arr;
    //     while(temp!=NULL){
    //         arr.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     int i=0, j=arr.size()-1, ans=0;
    //     while(i<j){
    //         ans=max(ans,arr[i]+arr[j]);
    //         i++; j--;
    //     }
    //     return ans;
    // }
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* prev=NULL;
        while(slow!=NULL){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        int ans=0;
        while(prev!=NULL){
            ans=max(ans,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return ans;
    }
};