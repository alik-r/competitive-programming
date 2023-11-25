struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int sz = 0;
    while (temp != NULL) {
        sz++;
        temp = temp->next;
    }

    int k = sz - n + 1;
    temp = head;
    if (k == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    struct ListNode* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}
