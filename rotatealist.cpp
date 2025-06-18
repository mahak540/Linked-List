Node* rotate(Node* head, int k) {
        // Your code here
        if(k==0 || head==NULL)
        return head;
        Node *curr=head;
        int len=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            len+=1;
        }
        k%=len;
        if(k==0)
        return head;
        
        curr->next=head;
        curr=head;
        
        for(int i=1;i<k;i++)
        
            curr=curr->next;
            head=curr->next;
            curr->next=NULL;
        
        return head;
    }
