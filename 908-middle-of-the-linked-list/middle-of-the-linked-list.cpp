class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // ListNode*slow=head;
        // ListNode*fast=head;
        // while(fast&&fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // return slow;
        //optimized;
        ListNode*temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
            int mid=count/2;
            temp=head;
            for(int i=0;i<mid;i++){
            temp=temp->next;
        }
        return temp;
    }
};