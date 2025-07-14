/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* current = head;
        while (current != nullptr) {
            n++;
            current = current->next;
        }

        int ans = 0;
        current = head;
        while (current != nullptr) {
            if (current->val == 1) {
                ans += (int)pow(2, n - 1);
            }
            n--;
            current = current->next;
        }
        return ans;
    }
};
