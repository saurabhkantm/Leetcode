class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          //dono list ko traverse kro
        //chote wale element ko ans mai daalo
        ListNode*dummynode=new ListNode(-1);
        ListNode*temp=dummynode;
        while(list1&&list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        temp->next=(list1!=NULL)?list1:list2;
        return dummynode->next;
    }
};