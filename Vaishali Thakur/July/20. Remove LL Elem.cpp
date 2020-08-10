class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        
        ListNode* curr = head, *prev = head;
        while(prev != NULL){
            curr = prev->next;
            while(curr != NULL &&  curr->val == val){
                curr = curr->next;           

            }
            prev->next = curr;
            prev = curr;
        }
        if(head->val == val){
            head = head->next;
        }
        return head;
    }
};