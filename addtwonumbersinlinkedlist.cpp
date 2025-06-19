class Solution {
public:
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
ListNode* trimLeadingZeros(ListNode* head) {
    while (head != nullptr && head->val == 0) {
        head = head->next;
    }
    return head;
}
int countNodes(ListNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 if (l1->val == 0 && l1->next == NULL && l2->val == 0 && l2->next == NULL) {
        return new ListNode(0);
    }

        l1 = trimLeadingZeros(l1);
    l2 = trimLeadingZeros(l2);
    
    int len1 = countNodes(l1);
    int len2 = countNodes(l2);
    
    if (len1 < len2)
        return addTwoNumbers(l2, l1);
    int carry = 0;
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode* res = l1;
    
    while (l2 != nullptr || carry != 0) {
        
        l1->val += carry;
        
        if (l2 != nullptr) {
            l1->val += l2->val;
            l2 = l2->next;
        }
      
        carry = l1->val / 10;
        
        l1->val = l1->val % 10;

        if (l1->next == nullptr && carry != 0)
            l1->next = new ListNode(0);
        l1 = l1->next;
    }
    
    return reverse(res);
    }
};
