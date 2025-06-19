class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (!head || left == right) return head;
    
    ListNode curr(0);
            curr.next = head;
    ListNode *prev = &curr;
    
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    ListNode *current = prev->next;
    ListNode *tail = current; 

    for (int i = left; i <= right; i++) {
        ListNode *next_node = current->next;
        current->next = prev->next;
        prev->next = current;
        current = next_node;
    }
   
    tail->next = current;
    return curr.next;
    }
};
