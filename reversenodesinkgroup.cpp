ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *prevfirst=NULL;
        bool isfirstpass=true;
         
         while (curr != NULL) {
        int count = 0;
        ListNode *first = curr;
        ListNode *prev = NULL;
       
        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            curr = first; 
            count = 0;
             while (count < k) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
        
            if (isfirstpass) {
                head = prev; 
                isfirstpass = false;
            } else {
                prevfirst->next = prev; 
            }
            prevfirst = first;

            } else {
           
            if (prevfirst != NULL) {
                prevfirst->next = first; 
            }
            break; 
        }
    }
    return head;

        
    }
