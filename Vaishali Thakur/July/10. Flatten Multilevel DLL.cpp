class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        Node* curr = head;
        while(curr && !curr->child){
            curr = curr->next;
        }
        Node* currNext;
        if(curr){
            currNext = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;
        }
        while(curr && curr->next){
            curr = curr->next;
        }
        if(curr){
            curr->next = currNext;
            if(currNext)
                currNext->prev = curr;
        }
        return head;
    }
};