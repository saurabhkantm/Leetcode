class Solution {
public:
    ListNode* reverseList(ListNode* node){
        if(node==NULL){
            return node;
        }
        ListNode* prev = NULL;
        ListNode* temp = node;
        ListNode* front = NULL;
        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    int findLength(ListNode* head){
        int curr = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            curr++;
            temp = temp->next;
        }
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }   
        int len = findLength(head);
        ListNode* temp = head;
        k = k % len;
        ListNode* pt2 = head;
        while(len-k>1){
            pt2 = pt2->next;
            k++;
        }
        ListNode* frt = pt2->next;
        pt2->next = NULL;
        ListNode* rev1 = reverseList(frt);
        ListNode* rev2 = reverseList(head);
        head->next = rev1;
        ListNode* ans = reverseList(rev2);
        return ans;
    }
};