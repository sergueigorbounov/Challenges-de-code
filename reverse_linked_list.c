/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL ||  left == right) {
        return head;
    }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) {
        prev = prev -> next;
    }
    struct ListNode* current = prev->next;
    struct ListNode* next = NULL;
    struct ListNode* reverse = NULL;
    for ( int i = 0; i <= right - left; i++) {
    next = current->next;
    current->next = reverse;
    reverse = current;
    current = next;
    }
    prev->next->next = current;
    prev->next = reverse;
    return dummy.next;
}
