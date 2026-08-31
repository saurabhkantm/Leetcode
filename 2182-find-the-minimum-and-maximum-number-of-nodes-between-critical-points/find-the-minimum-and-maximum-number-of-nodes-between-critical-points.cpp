class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(head == NULL || head->next == NULL || head->next->next == NULL)return ans;
        ListNode* prev = head, *curr = head->next, *front = head->next->next;
        int nodedis = 1;
        int firstdis = -1, lastdis = -1;
        int prevdis = INT_MAX;
        int mindis = INT_MAX;
        while(front != NULL){
            if((prev->val > curr->val && curr->val < front->val) || (prev->val < curr->val && front->val < curr->val)){
                if(firstdis == -1){
                    firstdis = nodedis;
                }
                if(prevdis != INT_MAX){
                    mindis = min(mindis, nodedis - prevdis);
                }
                lastdis = nodedis;
                prevdis = nodedis;
            }
            nodedis++;
            prev = curr;
            curr = front;
            front = front->next;

        }
        int maxdis = lastdis - firstdis;
        if(mindis == INT_MAX || maxdis == 0)return ans;
        ans = {mindis, maxdis};
        return ans;

        
    }
};