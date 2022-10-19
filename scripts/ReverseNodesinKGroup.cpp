ListNode* reverseKGroup(ListNode* head, int k) {
        int totL = 0;
        ListNode *dummyH = new ListNode(0);
        dummyH->next = head;
        
        ListNode *temp = head,*prev=dummyH,*curr,*nex;
        while(temp!=NULL){
            totL++;
            temp = temp->next;
        }
        
        int noI = totL/k;
        
        while(noI > 0){
            //NOTE: curr point to first Elem and nex points to second Elem
            curr = prev->next;
            nex = curr->next;
            
            //Note: for k , swap k-1 arrows
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            
            prev = curr;
            noI--;
        }
        return dummyH->next;
    }
