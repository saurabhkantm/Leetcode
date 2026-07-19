class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //    vector<int>ans;
    //    ListNode*curr=head;
    //    //store value
    //    while(curr){
    //    ans.push_back(curr->val);
    //    curr=curr->next;
    //    }
    //    //traverse again
    //    curr=head;
    //    // Step 3: Replace values in reverse order
    //    for(int i=ans.size()-1;i>=0;i--){
    //     curr->val=ans[i];
    //     curr=curr->next;
    //    }
    //    return head;
    ListNode*prev=nullptr;
    ListNode*curr=head;
    while(curr){
        ListNode*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
    }
};