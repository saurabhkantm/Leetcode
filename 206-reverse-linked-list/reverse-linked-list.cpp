class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Reverse the rest of the list
        ListNode* last = reverseList(head->next);

        // Put current node at the end
        head->next->next = head;
        head->next = nullptr;

        return last;
    }
};
