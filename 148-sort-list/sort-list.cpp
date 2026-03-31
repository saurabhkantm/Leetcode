class Solution {
public:
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* temp = new ListNode();
        ListNode* r = temp;

        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                r->next = p;
                p = p->next;
            } else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }

        if (p != NULL) {
            r->next = p;
        } else if (q != NULL) {
            r->next = q;
        }
        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* p = head;
        ListNode* q = head;
        ListNode* prev = NULL;

        while (q != NULL && q->next != NULL) {
            prev = p;
            p = p->next;
            q = q->next->next;
        }

        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(p);

        return merge(left, right);
    }
};