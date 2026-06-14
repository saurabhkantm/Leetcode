class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;

        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        int ans = 0;
        int l = 0, r = v.size() - 1;

        while(l<r){
            ans = max(ans, v[l] + v[r]);
            l++;
            r--;
        }

        return ans;
    }
};