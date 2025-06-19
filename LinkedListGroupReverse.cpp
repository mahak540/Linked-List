class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL)
        return head;
        Node *curr=head;
        Node *h1=NULL;
        Node *h2=NULL;
        
        while(curr!=NULL)
        {
            Node *group=curr;
            Node *prev=NULL;
            Node *nextnode=NULL;
            
            int cnt=0;
            
            while(curr!=NULL && cnt<k)
            {
                nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
                cnt++;
            }
            if(h1==NULL)
            {
                h1=prev;
            }
            if(h2!=NULL)
            {
                h2->next=prev;
            }
            h2=group;
        }
        return h1;
        
    }
};
